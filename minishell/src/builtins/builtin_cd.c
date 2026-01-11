/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:58 by briandri          #+#    #+#             */
/*   Updated: 2025/12/29 10:55:14 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cd(char **params, t_mlist **env)
{
	char	*path;
	char	*oldpwd;
	char	*newpwd;

	if (params[1] != 0 && params[2] != 0)
	{
		write(2, "minishell: cd: too many arguments\n", 35);
		return (1);
	}
	if ((!params[1]) || (params[1] && params[1][0] == '\0'))
		path = get_elem_env(*env, "HOME");
	else
		path = params[1];
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd && params[1] && (params[1][0] == '.' || params[1][0] == '/'))
	{
		if (params[1][0] == '.')
		{
			print_error("minishell: cd: ");
			print_error(params[1]);
			print_error(": No such file or directory\n");
			free(oldpwd);
			return (1);
		}
	}
	if (chdir(path) != 0)
	{
		print_error("minishell: cd: ");
		print_error(params[1]);
		print_error(": No such file or directory\n");
		free(oldpwd);
		return (1);
	}
	newpwd = getcwd(NULL, 0);
	return (free(oldpwd), free(newpwd), 0);
}
