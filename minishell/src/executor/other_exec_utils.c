/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_exec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 07:38:37 by harramar          #+#    #+#             */
/*   Updated: 2026/01/20 10:32:32 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	redirect_in_out(t_data *data, t_cmd *cmd, int *pip)
{
	close(pip[0]);
	if (cmd->infile >= 0)
	{
		dup2(cmd->infile, 0);
		close(cmd->infile);
	}
	if (cmd->outfile >= 0)
	{
		dup2(cmd->outfile, 1);
		close(cmd->outfile);
	}
	else if (cmd->next != data->cmd)
		dup2(pip[1], 1);
	close(pip[1]);
}

static void	built(int *pip, t_cmd *cmd, t_data *data)
{
	close(pip[0]);
	if (cmd->outfile < 0 && cmd->next != data->cmd)
		cmd->outfile = pip[1];
	else
		close(pip[1]);
	launch_builtin(data, cmd);
}

static int	handle_builtin_or_skip(t_data *data, t_cmd *cmd, int *pip)
{
	if (cmd->skip_cmd)
	{
		data->exit_code = 1;
		return (1);
	}
	if (is_builtin(cmd->cmd_param[0]))
	{
		built(pip, cmd, data);
		return (1);
	}
	return (0);
}

static void	execute_external_cmd(t_data *data, t_cmd *cmd, int *pip)
{
	char	*path;
	char	**env;

	path = NULL;
	if (cmd_exist(&path, data, cmd->cmd_param[0]))
	{
		redirect_in_out(data, cmd, pip);
		env = lst_to_arr(data->env);
		if (!env)
			free_all(data, ERR_MALLOC, EXT_MALLOC);
		rl_clear_history();
		signals2();
		execve(path, cmd->cmd_param, env);
		free(env);
	}
	else
	{
		close(pip[0]);
		close(pip[1]);
	}
	if (path)
		free(path);
}

void	child_process(t_data *data, t_cmd *cmd, int *pip)
{
	signal(SIGINT, SIG_DFL);
	if (!handle_builtin_or_skip(data, cmd, pip))
		execute_external_cmd(data, cmd, pip);
	free_all(data, NULL, data->exit_code);
}
