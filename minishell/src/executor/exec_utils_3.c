/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:30:55 by briandri          #+#    #+#             */
/*   Updated: 2026/01/20 10:40:08 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_cmd(t_data *data, char *cmd)
{
	if (!create_paths(data->env, len_list(data->env)) && access(cmd, F_OK) == 0)
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
		print_not_found(data, cmd);
		return (0);
	}
	return (1);
}

int	cmd_exist(char **path, t_data *data, char *cmd)
{
	struct stat	st;

	*path = NULL;
	if (ft_strchr(cmd, '/'))
		*path = ft_strdup(cmd);
	else
		*path = find_cmd(data, cmd, data->env);
	if ((*path) == NULL)
	{
		if (check_cmd(data, cmd) == 0)
			return (0);
	}
	if (stat(*path, &st) != 0)
	{
		cmd_not_exist(path, cmd);
		return (data->exit_code = 127, 0);
	}
	if (!check_dir(path, cmd, data))
		return (0);
	if (access(*path, X_OK) != 0)
	{
		cmd_not_exist(path, cmd);
		return (data->exit_code = 126, 0);
	}
	return (1);
}

int	handle_exec_special_cases(t_data *data, t_cmd *tmp)
{
	if (data->attr_error != 0)
		return (1);
	if (!tmp)
		return (0);
	if (tmp->skip_cmd == false && tmp->next == tmp && tmp->cmd_param
		&& tmp->cmd_param[0] && is_builtin(tmp->cmd_param[0]))
		return (launch_builtin(data, tmp));
	return (-1);
}

int	exec_pipeline(t_data *data, t_cmd *tmp, int *pip)
{
	pid_t	p;

	if (pipe(pip) == -1)
		return (-1);
	close(pip[1]);
	p = exec_cmd(data, tmp, pip);
	tmp = tmp->next;
	while (tmp != data->cmd)
	{
		if (pipe(pip) == -1)
			return (-1);
		p = exec_cmd(data, tmp, pip);
		tmp = tmp->next;
	}
	return (wait_all(data, p), 1);
}
