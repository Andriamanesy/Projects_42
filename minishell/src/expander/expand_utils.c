/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:47:36 by briandri          #+#    #+#             */
/*   Updated: 2025/12/29 11:42:22 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_char(char *c, char **str, t_data *data, int *index)
{
	char	char_to_str[2];
	char	*tmp;

	(void)data;
	char_to_str[0] = *c;
	char_to_str[1] = '\0';
	tmp = ft_strjoin(*str, char_to_str);
	if (!tmp)
		return (0);
	free(*str);
	*str = tmp;
	(*index)++;
	return (1);
}

char	*get_dollar_word(char *line, int size)
{
	char	*key;
	int		j;

	key = malloc(sizeof(char) * (size + 1));
	if (!key)
		return (NULL);
	j = 0;
	while (j < size)
	{
		key[j] = line[j];
		j++;
	}
	key[j] = '\0';
	return (key);
}

static char	*get_dollar_value(char *line, int *len_key, t_data *data)
{
	char	*key;
	char	*value;

	*len_key = 0;
	if (line[0] == '?')
	{
		value = ft_itoa(data->exit_code);
		*len_key = 1;
	}
	else
	{
		while (line[*len_key] && (ft_isalnum(line[*len_key])
				|| line[*len_key] == '_'))
			(*len_key)++;
		key = get_dollar_word(line, *len_key);
		if (!key)
			return (NULL);
		value = get_elem_env(data->env, key);
		free(key);
	}
	return (value);
}

int	add_dollar(char *line, int *i, char **str, t_data *data)
{
	char	*value;
	char	*tmp;
	int		len_key;

	(*i)++;
	len_key = 0;
	value = get_dollar_value(&line[*i], &len_key, data);
	if (!value)
		tmp = ft_strjoin(*str, "");
	else
	{
		tmp = ft_strjoin(*str, value);
		free(value);
	}
	if (!tmp)
		return (0);
	free(*str);
	*str = tmp;
	*i += len_key;
	return (1);
}
