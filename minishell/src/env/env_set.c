/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:09:53 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 00:21:52 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	env_set(t_mlist *env, char *elem)
{
	char	*str1;
	char	*str2;
	char	*tmp;
	t_mlist	*tmp_env;
	int		len_env;

	str1 = get_env_name(elem);
	tmp_env = env;
	len_env = len_list(tmp_env);
	while (len_env--)
	{
		str2 = get_env_name(env->content);
		if (ft_strcmp(str1, str2) == 0)
		{
			tmp = env->content;
			env->content = ft_strdup(elem);
			free(str2);
			free(str1);
			return ;
		}
		free(str2);
		env = env->next;
	}
	free(str1);
}
