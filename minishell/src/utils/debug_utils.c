/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:56:02 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 16:59:23 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	print_tab(char **tab)
// {
// 	int	i;

// 	if (!(tab))
// 	{
// 		printf("NULL");
// 		return ;
// 	}
// 	i = 0;
// 	printf("[");
// 	while (tab[i])
// 	{
// 		printf("%s", tab[i]);
// 		if (tab[i + 1])
// 			printf(", ");
// 		i++;
// 	}
// 	printf("]");
// }

// void	print_cmd(t_cmd *cmd)
// {
// 	t_cmd	*tmp;

// 	tmp = cmd;
// 	while (tmp->next != cmd)
// 	{
// 		printf("Skip -> %d, infile -> %d, outfile -> %d, cmd : ", tmp->skip_cmd,
// 			tmp->infile, tmp->outfile);
// 		print_tab(tmp->cmd_param);
// 		printf("\n");
// 		tmp = tmp->next;
// 	}
// 	printf("Skip -> %d, infile -> %d, outfile -> %d, cmd : ", tmp->skip_cmd,
// 		tmp->infile, tmp->outfile);
// 	print_tab(tmp->cmd_param);
// 	printf("\n");
// }
