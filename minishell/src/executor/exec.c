/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:37 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 13:49:25 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void parent_process(t_data *data, t_cmd *cmd, int *pip)
{
    close(pip[1]);
    if (cmd->infile >= 0)
        close(cmd->infile);
    if (cmd->infile == -2)
        cmd->infile = pip[0];
    if (cmd->next != data->cmd && cmd->next->infile == -2)
        cmd->next->infile = pip[0];
    else
        close(pip[0]);
}

static int  exec_cmd(t_data *data, t_cmd *cmd, int *pip)
{
    g_signal_pid = fork();
    if (g_signal_pid < 0)
        return (perror("fork"), 0);
    if (g_signal_pid == 0)
    {
        // Sécurité Redirection
        if (cmd->redir_error == true)
            free_all(data, NULL, 1);
        // Sécurité Mémoire : si cmd_param est NULL, on ne touche à rien
        if (cmd->cmd_param && cmd->cmd_param[0])
            child_process(data, cmd, pip);
        else
            free_all(data, NULL, 0);
    }
    else
        parent_process(data, cmd, pip);
    return (1);
}

static void wait_all(t_data *data)
{
    int     status;
    int     pid;
    int     len;
    t_cmd   *tmp;

    tmp = data->cmd;
    len = len_cmd(tmp);
    while (len--)
    {
        pid = waitpid(0, &status, 0);
        if (pid == g_signal_pid)
        {
            if (WIFEXITED(status))
                data->exit_code = WEXITSTATUS(status);
            else if (WIFSIGNALED(status))
                data->exit_code = 128 + WTERMSIG(status);
        }
        if (tmp->outfile >= 0)
            close(tmp->outfile);
        if (tmp->infile >= 0)
            close(tmp->infile);
        tmp = tmp->next;
    }
}

int exec(t_data *data)
{
    t_cmd   *tmp;
    int     *pip;

    pip = data->pip;
    tmp = data->cmd;
    if (!tmp)
        return (0);
    // PROTECTION CRITIQUE : on vérifie que cmd_param et cmd_param[0] existent
    if (tmp->skip_cmd == false && tmp->next == tmp 
        && tmp->cmd_param && tmp->cmd_param[0] 
        && is_builtin(tmp->cmd_param[0]))
        return (launch_builtin(data, tmp));
    if (pipe(pip) == -1)
        return (0);
    exec_cmd(data, tmp, pip);
    tmp = tmp->next;
    while (tmp != data->cmd)
    {
        if (pipe(pip) == -1)
            return (-1);
        exec_cmd(data, tmp, pip);
        tmp = tmp->next;
    }
    wait_all(data);
    signal(SIGINT, handle_sigint);
    return (1);
}