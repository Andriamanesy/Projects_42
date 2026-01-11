/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:09:44 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 02:37:31 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_search(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (0);
}

static int	end_word(char *str, char *env)
{
	int	i;

	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		++i;
	if (i == ft_search(env, '='))
		return (i);
	return (0);
}

int	exist_in_env(char *line, int *i, t_data *data)
{
	t_mlist	*tmp;
	int		len;

	if (line[*i + 1] == '?' || line[*i + 1] == '$')
		return (2);
	tmp = data->env;
	len = len_list(tmp);
	while (len--)
	{
		if (ft_strncmp(tmp->content, &line[*i + 1], end_word(&line[*i + 1],
					tmp->content)) == 0)
		{
			*i += ft_strlen(tmp->content) - ft_strlen(ft_strchr(tmp->content,
						'=')) + 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*get_env_name(char *env)
{
	int	i;

	i = end_word(env, env);
	if (i > 0)
		return (ft_substr(env, 0, i));
	return (NULL);
}

char	*get_elem_env(t_mlist *env, char *key)
{
	t_mlist	*tmp;
	int		len;
	int		t;

	if (!key)
		return (NULL);
	tmp = env;
	len = len_list(tmp);
	t = ft_strlen(key);
	while (len--)
	{
		if (ft_strncmp(tmp->content, key, t) == 0)
		{
			len = 0;
			while (tmp->content[len])
				if (tmp->content[len++] == '=')
					break ;
			return (ft_strdup(&(tmp->content[len])));
		}
		tmp = tmp->next;
	}
	return (NULL);
}
