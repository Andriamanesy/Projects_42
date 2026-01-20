/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:35 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 02:37:31 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// # include <stddef.h>

typedef struct s_mlist	t_mlist;
typedef struct s_data	t_data;
typedef struct s_token	t_token;

int						free_list(t_mlist **list);
int						append(t_mlist **list, char *elem);
size_t					len_list(t_mlist *list);
int						print_error(char *str);
void					free_all(t_data *data, char *err, int ext);
int						print_error_token(t_token *token, t_data *data);
void					absolute_path(char **path, char *cmd, t_data *data);
int						empty_line(char *line);

#endif
