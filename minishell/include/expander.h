/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 07:23:46 by harramar          #+#    #+#             */
/*   Updated: 2026/01/11 17:55:14 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <stdbool.h>

typedef struct s_data	t_data;

void					open_quote(char **str);
char					*get_dollar_word(char *line, int size);
int						add_dollar(char *line, int *index, char **str,
							t_data *data);
int						add_char(char *c, char **str, t_data *data, int *index);
int						replace_dollar(char **line, t_data *data, int redir);
int						here_doc(t_data *data, char *word);
void					heredoc_sigint(int code);
void					other_sigint(int code);
void					heredoc_eof_warning(char *word);

#endif
