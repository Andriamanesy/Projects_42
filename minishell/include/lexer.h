/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:18 by briandri          #+#    #+#             */
/*   Updated: 2026/01/17 11:19:41 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_token	t_token;

int						create_list_token(t_token **begin, char *command);
int						append_token(t_token **list, char *str, int type);
void					free_token(t_token **list);
int						is_space(char c);
int						is_special(char *str);
int						check_open_quote(t_data *data, char *line);
char					*rm_quote(char *dst, char *src);
int						count_quote(char *str);

#endif
