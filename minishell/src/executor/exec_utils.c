/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:33 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 16:56:14 by briandri         ###   ########.fr       */
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

static int	ft_count(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
		{
			i++;
		}
		if (str[i])
		{
			while (str[i] && str[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		len;

	str = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (len < i)
			str[j++] = ft_substr(s, len, (i - len));
	}
	str[j] = NULL;
	return (str);
}

char	*find_cmd(t_data *data, char *cmd, t_mlist *env)
{
	char	*paths;
	char	*path;
	char	*tmp;
	char	**split;
	int		i;

	(void)data;
	paths = create_paths(env, len_list(env));
	if (!paths)
		return (NULL);
	i = 0;
	split = ft_split(paths, ':');
	while (split[i])
	{
		tmp = ft_strjoin(split[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (free_cmd_param(split), path);
		free(path);
		i++;
	}
	free_cmd_param(split);
	return (NULL);
}
