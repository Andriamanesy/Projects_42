/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:44:43 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 01:24:02 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*int	check_pipe(t_data *data)
{
	if (data->token->type == PIPE)
	{
		write(2, "syntax error near unexpected token '|'\n", 39);
		free_token(&data->token);
		free_cmd(&data->cmd);
		return (0);
	}
	return (1);
}*/

int	check_pipe(t_data *data)
{
	int		first_pass;
	t_token	*tmp;

	first_pass = 1;
	tmp = data->token;
	if (tmp->type == PIPE)
	{
		write(2, "syntax error near unexpected token '|'\n", 39);
		free_token(&data->token);
		free_cmd(&data->cmd);
		return (0);
	}
	while (tmp && (first_pass || tmp != data->token))
	{
		first_pass = 0;
		if (tmp->type == PIPE)
		{
			if (!tmp->next || tmp->next->type == PIPE)
			{
				write(2, "syntax error near unexpected token '|'\n", 39);
				free_token(&data->token);
				free_cmd(&data->cmd);
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
