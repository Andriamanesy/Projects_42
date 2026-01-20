/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:09:08 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 16:55:00 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(t_mlist *env)
{
	t_mlist	*temp;

	temp = env;
	if (!temp)
		return (0);
	if (ft_strchr(temp->content, '='))
		printf("%s\n", temp->content);
	temp = temp->next;
	while (temp != env)
	{
		if (ft_strchr(temp->content, '='))
			printf("%s\n", temp->content);
		temp = temp->next;
	}
	return (0);
}
