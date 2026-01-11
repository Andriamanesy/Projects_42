/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:07:46 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 02:37:31 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_mlist	t_mlist;
typedef struct s_data	t_data;

typedef struct s_var
{
	int					has_digit;
	int					invalid_arg;
}						t_var;

int						ft_echo(char **args);
int						ft_pwd(void);
int						ft_cd(char **params, t_mlist **env);
void					ft_exit(t_data *data, char **args);

#endif
