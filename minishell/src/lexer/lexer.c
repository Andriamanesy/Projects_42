/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:54 by briandri          #+#    #+#             */
/*   Updated: 2025/12/23 23:20:59 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	length_cmd(char *command, int *quotes)
{
	int	i;

	i = 0;
	if (quotes)
		*quotes = 0;
	while (command[i] && !is_space(command[i]) && !is_special(command + i))
	{
		if (command[i] == '"' || command[i] == '\'')
		{
			if (quotes)
				(*quotes)++;
			if (command[i++] == '"')
				while (command[i] && command[i] != '"')
					++i;
			else
				while (command[i] && command[i] != '\'')
					++i;
			if (command[i])
				++i;
		}
		if (command[i] && command[i] != '"' && command[i] != '\''
			&& !is_space(command[i]) && !is_special(command + i))
			++i;
	}
	return (i);
}

static void	copy_token(char *command, int length, char *str, int i)
{
	int j = 0;

	while (j < length)
	{
		if ((command[j] == '"' || command[j] == '\'') && length > 1)
		{
			char quote = command[j];
			j++;
			while (j < length && command[j] != quote)
			{
				str[i++] = command[j++];
			}
			j++;
		}
		else
		{
			str[i++] = command[j++];
		}
	}
	str[i] = '\0';
}

static void	copy_token_raw(char *command, int length, char *str, int i)
{
	int j = 0;

	while (j < length)
	{
		str[i++] = command[j++];
	}
	str[i] = '\0';
}


static int	add_cmd(t_token **begin, char **command)
{
	char	*str;
	int		length;
	int		quotes;
	int		i;

	i = 0;
	length = length_cmd(*command, &quotes);
	if ((length) <= 0)
		return (1);
	str = malloc(sizeof(char) * ((length + 1)));
	if (!str)
		return (0);
	copy_token(*command, length, str, i);
	if (!append_token(begin, str, 0))
		return (0);
	if ((*begin)->prev == (*begin) || (*begin)->prev->prev->type == PIPE)
		(*begin)->prev->type = CMD;
	else
		(*begin)->prev->type = ARG;
	(*command) += length;
	return (1);
}


static int	add_var_cmd(t_token **begin, char **command)
{
	char	*str;
	int		length;
	int		i;

	i = 0;
	length = length_cmd(*command, NULL);
	if (length <= 0)
		return (1);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);

	copy_token_raw(*command, length, str, i);

	if (!append_token(begin, str, 0))
		return (0);

	if ((*begin)->prev == (*begin) || (*begin)->prev->prev->type == PIPE)
		(*begin)->prev->type = CMD;
	else
		(*begin)->prev->type = ARG;

	(*command) += length;
	return (1);
}


static int	add_special(t_token **begin, char **command)
{
	int	spe;

	spe = is_special(*command);
	if (!spe)
		return (0);
	if (spe == INPUT && !append_token(begin, ft_strdup("<"), INPUT))
		return (0);
	else if (spe == HEREDOC && !append_token(begin, ft_strdup("<<"), HEREDOC))
		return (0);
	else if (spe == TRUNC && !append_token(begin, ft_strdup(">"), TRUNC))
		return (0);
	else if (spe == APPEND && !append_token(begin, ft_strdup(">>"), APPEND))
		return (0);
	else if (spe == PIPE && !append_token(begin, ft_strdup("|"), PIPE))
		return (0);
	if (spe == INPUT || spe == TRUNC || spe == PIPE)
		(*command)++;
	else if (spe == HEREDOC || spe == APPEND)
		(*command) += 2;
	return (1);
}

static int	is_export_context(t_token *begin)
{
	if (!begin)
		return (0);
	if (begin->prev
		&& begin->prev->type == CMD
		&& !ft_strncmp(begin->prev->str, "export", 6))
		return (1);
	return (0);
}


int	create_list_token(t_token **begin, char *command)
{
	*begin = NULL;
	while (*command)
	{
		while (is_space(*command))
			command++;

		if (*command && !is_special(command))
		{
			if (*begin && (*begin)->prev && is_export_context((*begin)->prev))
			{
				if (!add_var_cmd(begin, &command))
				{
					free_token(begin);
					return (0);
				}
			}
			else if (!add_cmd(begin, &command))
			{
				free_token(begin);
				return (0);
			}
		}
		else if (*command && is_special(command)
			&& !add_special(begin, &command))
		{
			free_token(begin);
			return (0);
		}
	}
	return (1);
}

