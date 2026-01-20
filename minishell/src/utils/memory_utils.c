/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:48 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 16:59:37 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_all(t_data *data, char *err, int ext)
{
	if (data)
	{
		free_list(&data->env);
		free_token(&data->token);
		free_cmd(&data->cmd);
	}
	if (err)
		write(2, err, ft_strlen(err));
	exit(ext);
}
