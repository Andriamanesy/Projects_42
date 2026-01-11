/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:33 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 02:37:31 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	absolute_path(char **path, char *cmd, t_data *data)
{
	*path = ft_strdup(cmd);
	if (!(*path))
		free_all(data, ERR_MALLOC, EXT_MALLOC);
	if (access((*path), F_OK))
	{
		write(2, (*path), ft_strlen((*path)));
		write(2, " : command not found\n", 21);
		free(*path);
		*path = NULL;
	}
}

int	ft_strslashjoin(char *dest, char *str, char *env, int *index)
{
	int	i;
	int	j;

	i = 0;
	while (*index < (PATH_MAX - 1) && env[(*index)] && env[(*index)] != ':')
		dest[i++] = env[(*index)++];
	++(*index);
	dest[i++] = '/';
	j = 0;
	while (j < (PATH_MAX - 1) && str[j])
		dest[i++] = str[j++];
	dest[i] = '\0';
	return (0);
}

char	*create_paths(t_mlist *env, int len)
{
	t_mlist	*tmp;

	tmp = env;
	while (len--)
	{
		if (ft_strncmp(tmp->content, "PATH=", 5) == 0)
			return (&(tmp->content[5]));
		tmp = tmp->next;
	}
	return (NULL);
}

char	*find_cmd(t_data *data, char *cmd, t_mlist *env)
{
	char	*paths;
	char	path[PATH_MAX];
	int		i;

	(void)data;
	paths = create_paths(env, len_list(env));
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		ft_strslashjoin(path, cmd, paths, &i);
		if (access(path, F_OK) == 0)
			return (ft_strdup(path));
	}
	return (NULL);
}
