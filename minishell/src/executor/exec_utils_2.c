/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:12:50 by harramar          #+#    #+#             */
/*   Updated: 2026/01/17 14:12:58 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_not_found(t_data *data, char *cmd)
{
	print_error(cmd);
	print_error(" : command not found\n");
	data->exit_code = 127;
}

void	cmd_not_exist(char **path, char *cmd)
{
	perror(cmd);
	free(*path);
	*path = NULL;
}

int	check_dir(char **path, char *cmd, t_data *data)
{
	char		*tmp;
	struct stat	path_stat;

	if (!cmd || ft_strlen(cmd) == 0)
	{
		print_not_found(data, cmd);
		return (0);
	}
	tmp = get_elem_env(data->env, "PATH");
	if (((ft_strcmp(cmd, "..") == 0) || ft_strcmp(cmd, ".") == 0) && tmp)
	{
		print_not_found(data, cmd);
		return (free(tmp), 0);
	}
	free(tmp);
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
