/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_exec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 07:38:37 by harramar          #+#    #+#             */
/*   Updated: 2025/12/29 07:38:39 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_dir(char **path, char *cmd, t_data *data)
{
	struct stat	path_stat;

	if (!cmd || ft_strlen(cmd) == 0)
	{
		data->exit_code = 127;
		write(2, " : command not found\n", 21);
		return (0);
	}
	if (ft_strcmp(cmd, "..") == 0)
	{
		print_error(cmd);
		print_error(" : command not found\n");
		data->exit_code = 127;
		return (0);
	}
	stat(*path, &path_stat);
	if (!S_ISREG(path_stat.st_mode))
	{
		print_error(cmd);
		print_error(" : Is a directory\n");
		data->exit_code = 126;
		return (0);
	}
	return (1);
}

static int	cmd_exist(char **path, t_data *data, char *cmd)
{
	struct stat	st;

	*path = NULL;
	if (ft_strchr(cmd, '/'))
		*path = ft_strdup(cmd);
	else
		*path = find_cmd(data, cmd, data->env);
	if ((*path) == NULL)
	{
		if (!create_paths(data->env, len_list(data->env)) && access(cmd,
				F_OK) == 0)
		{
			if (access(cmd, X_OK) == 0)
			{
				if (!check_dir(&cmd, cmd, data))
					return (0);
				else
					execve(cmd, data->cmd->cmd_param, lst_to_arr(data->env));
			}
			else
			{
				perror(cmd);
				return (0);
			}
		}
		else
		{
			write(2, cmd, ft_strlen(cmd));
			write(2, " : command not found\n", 21);
			data->exit_code = 127;
			return (0);
		}
	}
	if (stat(*path, &st) != 0)
	{
		perror(cmd);
		free(*path);
		*path = NULL;
		data->exit_code = 127;
		return (0);
	}
	if (!check_dir(path, cmd, data))
		return (0);
	if (access(*path, X_OK) != 0)
	{
		perror(cmd);
		free(*path);
		*path = NULL;
		data->exit_code = 126;
		return (0);
	}
	return (1);
}

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

void	child_process(t_data *data, t_cmd *cmd, int *pip)
{
	char	*path;
	char	**env;

	path = NULL;
	signal(SIGINT, SIG_DFL);
	if (cmd->skip_cmd)
		data->exit_code = 1;
	else if (is_builtin(cmd->cmd_param[0]))
		built(pip, cmd, data);
	else if (cmd_exist(&path, data, cmd->cmd_param[0]))
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
	if (path)
		free(path);
	free_all(data, NULL, data->exit_code);
}
