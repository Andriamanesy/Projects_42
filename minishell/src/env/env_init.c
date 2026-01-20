/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:52:43 by harramar          #+#    #+#             */
/*   Updated: 2026/01/17 13:52:57 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_last_underscore(t_data *data, t_cmd *cmd)
{
	char	*tmp;
	char	*last_arg;
	int		argc;

	if (!data || !data->env || !cmd || !cmd->cmd_param)
		return ;
	argc = 0;
	while (cmd->cmd_param[argc])
		argc++;
	if (argc == 0)
		return ;
	last_arg = cmd->cmd_param[argc - 1];
	if (!last_arg)
		return ;
	tmp = ft_strjoin("_=", last_arg);
	if (!tmp)
		return ;
	env_set(data->env, tmp);
	free(tmp);
}

static void	function_shlvl(t_data *data)
{
	int		i;
	char	*shlvl;
	char	*tmp;
	char	*str;

	i = 0;
	shlvl = get_elem_env(data->env, "SHLVL");
	if (shlvl)
		i = ft_atoi(shlvl);
	i++;
	tmp = ft_itoa(i);
	str = ft_strjoin("SHLVL=", tmp);
	env_set(data->env, str);
	free(shlvl);
	free(tmp);
	free(str);
}

static int	make_env2(t_data *data)
{
	char	path[PATH_MAX];
	char	*tmp;

	if (!getcwd(path, PATH_MAX))
	{
		free_all(data, ERR_MALLOC, EXT_MALLOC);
		return (0);
	}
	tmp = ft_strjoin("PWD=", path);
	if (!tmp || !append(&data->env, tmp))
	{
		free_all(data, ERR_MALLOC, EXT_MALLOC);
		return (0);
	}
	tmp = ft_strdup("SHLVL=1");
	if (!tmp || !append(&data->env, tmp))
	{
		free_all(data, ERR_MALLOC, EXT_MALLOC);
		return (0);
	}
	tmp = ft_strdup("_=./minishell");
	if (!tmp || !append(&data->env, tmp))
		return (free_all(data, ERR_MALLOC, EXT_MALLOC), 0);
	return (1);
}

int	make_env(t_data *data, char **env)
{
	t_mlist	*list;
	int		i;
	char	*tmp;

	if (!(*env))
		return (make_env2(data));
	i = 0;
	list = NULL;
	while (*env && env[i])
	{
		tmp = ft_strdup(env[i]);
		if (!tmp)
			return (free_list(&list), free(tmp), 0);
		if (!append(&list, tmp))
			return (free_list(&list), free(tmp), 0);
		i++;
	}
	data->env = list;
	function_shlvl(data);
	return (1);
}
