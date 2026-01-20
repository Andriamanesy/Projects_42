/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:24:06 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 17:26:07 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_infile(t_data *data, t_token *tmp)
{
	if (get_infile(data, tmp, data->cmd->prev) == 0
		/*&& data->cmd->prev->infile == -1*/)
		return (0);
	if (data->cmd->prev->infile == -1)
	{
		data->cmd->prev->skip_cmd = true;
		data->cmd->prev->outfile = -1;
		return (1);
	}
	return (1);
}

int	handle_outfile(t_data *data, t_token *tmp)
{
	if (!get_outfile(tmp, data->cmd->prev, data)
		/*&& data->cmd->prev->outfile != -1*/)
		return (0);
	if (!get_outfile(tmp, data->cmd->prev, data))
	{
		if (data->cmd->prev->outfile == -1)
		{
			if (data->cmd->prev->infile >= 0)
				close(data->cmd->prev->infile);
			data->cmd->prev->skip_cmd = true;
			data->cmd->prev->infile = -1;
		}
		return (0);
	}
	return (1);
}

int	handle_cmd_param(t_data *data, t_token *tmp)
{
	data->cmd->prev->cmd_param = get_param(data, tmp);
	if (!data->cmd->prev->cmd_param)
		free_all(data, ERR_MALLOC, EXT_MALLOC);
	return (1);
}
