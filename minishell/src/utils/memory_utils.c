/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:48 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 02:03:41 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	if (arr)
		free(arr);
	arr = NULL;
}

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
