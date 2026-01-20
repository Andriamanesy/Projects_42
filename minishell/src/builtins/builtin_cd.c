/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:58 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 18:03:01 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*get_cd_path(char **params, t_mlist **env, char *oldpwd)
{
	char	*path;

	if ((!params[1]) || (params[1] && params[1][0] == '\0'))
		path = get_elem_env(*env, "HOME");
	else
		path = params[1];
	if (!oldpwd && params[1] && params[1][0] == '.')
	{
		if (!chdir(path))
		{
			print_error("minishell: cd: ");
			print_error(params[1]);
			print_error(": No such file or directory\n");
			return (NULL);
		}
	}
	return (path);
}

static void	update_env(char *oldpwd, char *pwd, t_mlist **env)
{
	char	*tmp1;
	char	*tmp2;
	char	*true_pwd;
	char	*true_old_pwd;

	tmp1 = ft_strdup("PWD=");
	tmp2 = ft_strdup("OLDPWD=");
	true_old_pwd = ft_strjoin(tmp2, oldpwd);
	true_pwd = ft_strjoin(tmp1, pwd);
	export(true_old_pwd, env);
	export(true_pwd, env);
	free (tmp1);
	free (tmp2);
	free(true_old_pwd);
	free(true_pwd);
}

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
	oldpwd = getcwd(NULL, 0);
	path = get_cd_path(params, env, oldpwd);
	if (!path)
		return (free(oldpwd), 1);
	if (chdir(path) != 0)
	{
		print_error("minishell: cd: ");
		print_error(params[1]);
		print_error(": No such file or directory\n");
		return (free(oldpwd), 1);
	}
	newpwd = getcwd(NULL, 0);
	update_env(oldpwd, newpwd, env);
	return (free(oldpwd), free(newpwd), 0);
}
