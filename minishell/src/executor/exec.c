/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:55:47 by harramar          #+#    #+#             */
/*   Updated: 2026/01/20 10:42:47 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	parent_process(t_data *data, t_cmd *cmd, int *pip)
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

pid_t	exec_cmd(t_data *data, t_cmd *cmd, int *pip)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (perror("fork"), 0);
	if (pid == 0)
	{
		if (cmd->redir_error == true)
			free_all(data, NULL, 1);
		if (cmd->cmd_param && cmd->cmd_param[0])
			child_process(data, cmd, pip);
		else
			free_all(data, NULL, 0);
	}
	else
		parent_process(data, cmd, pip);
	return (pid);
}

static void	wait2(int len, int i, t_cmd *tmp)
{
	signal(SIGINT, SIG_IGN);
	while (len--)
	{
		if (i != -1)
			waitpid(-1, &i, 0);
		else
			waitpid(-1, NULL, 0);
		if (WIFSIGNALED(i))
		{
			printf("\n");
			i = -1;
		}
		if (tmp->outfile >= 0)
			close(tmp->outfile);
		if (tmp->infile >= 0)
			close(tmp->infile);
		tmp = tmp->next;
	}
	signal(SIGINT, handle_sigint);
}

void	wait_all(t_data *data, pid_t p)
{
	int		status;
	pid_t	pid;
	int		len;
	t_cmd	*tmp;
	int		i;

	tmp = data->cmd;
	len = len_cmd(tmp);
	pid = p;
	i = 0;
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	data->exit_code = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			printf("Quit (core dumped)\n");
		else
			printf("\n");
		i = -1;
		data->exit_code = 128 + WTERMSIG(status);
	}
	len--;
	wait2(len, i, tmp);
}

int	exec(t_data *data)
{
	t_cmd	*tmp;
	int		*pip;
	int		ret;

	tmp = data->cmd;
	ret = handle_exec_special_cases(data, tmp);
	if (ret != -1)
		return (ret);
	pip = data->pip;
	return (exec_pipeline(data, tmp, pip));
}
