/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:20 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 16:58:26 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	count_args(t_data *data, t_token *token)
{
	int		count;
	t_token	*tmp;

	count = 0;
	tmp = token;
	if (tmp->type == CMD || (tmp->type == ARG && tmp->prev != data->token->prev
			&& tmp->prev->type > 5))
		count++;
	tmp = tmp->next;
	while (tmp != data->token && tmp->type != PIPE)
	{
		if (tmp->type == CMD || (tmp->type == ARG
				&& tmp->prev != data->token->prev && tmp->prev->type > 5))
			count++;
		tmp = tmp->next;
	}
	return (count);
}

static int	add_to_cmd_param(char **cmd_param, int *i, char *str)
{
	cmd_param[*i] = ft_strdup(str);
	if (!cmd_param[*i])
		return (0);
	(*i)++;
	return (1);
}

void	*free_cmd_param(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
	return (NULL);
}

char	**get_param(t_data *data, t_token *token)
{
	char	**cmd_param;
	int		i;
	t_token	*tmp;

	i = 0;
	cmd_param = malloc(sizeof(char *) * (count_args(data, token) + 1));
	if (cmd_param == NULL)
		return (NULL);
	tmp = token;
	if (tmp->type != PIPE && (tmp->type == CMD || (tmp->type == ARG
				&& tmp->prev != data->token->prev && tmp->prev->type > 5))
		&& !add_to_cmd_param(cmd_param, &i, tmp->str))
		return (free_cmd_param(cmd_param));
	tmp = tmp->next;
	while (tmp != data->token && tmp->type != PIPE)
	{
		if ((tmp->type == CMD || (tmp->type == ARG
					&& tmp->prev != data->token->prev && tmp->prev->type > 5))
			&& !add_to_cmd_param(cmd_param, &i, tmp->str))
			return (free_cmd_param(cmd_param));
		tmp = tmp->next;
	}
	cmd_param[i] = NULL;
	return (cmd_param);
}
