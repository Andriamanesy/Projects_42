/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:10:54 by briandri          #+#    #+#             */
/*   Updated: 2026/01/17 13:58:16 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	length_cmd(char *command)
{
	int		i;
	char	quote;

	i = 0;
	while (command[i] && !is_space(command[i]) && !is_special(command + i))
	{
		if (command[i] == '"' || command[i] == '\'')
		{
			quote = command[i++];
			while (command[i] && command[i] != quote)
				i++;
			if (command[i])
				i++;
		}
		else
			i++;
	}
	return (i);
}

static void	copy_token(char *command, int length, char *str, int i)
{
	int	j;

	j = 0;
	while (command[i + j] && i < length)
	{
		str[i] = command[i + j];
		i++;
	}
	str[i] = 0;
}

static int	add_cmd(t_token **begin, char **command)
{
	char	*str;
	int		length;
	int		i;

	i = 0;
	length = length_cmd(*command);
	if ((length) < 0)
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

int	create_list_token(t_token **begin, char *command)
{
	(*begin) = NULL;
	while (*command)
	{
		while (is_space(*command))
			command++;
		if (*command && !is_special(command) && !add_cmd(begin, &command))
		{
			if (*begin)
				free_token(begin);
			return (0);
		}
		else if (*command && is_special(command) && !add_special(begin,
				&command))
		{
			if (*begin)
				free_token(begin);
			return (0);
		}
	}
	return (1);
}
