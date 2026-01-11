/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 07:23:46 by harramar          #+#    #+#             */
/*   Updated: 2025/12/29 07:23:53 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <stdbool.h>

typedef struct s_data	t_data;

void					quoting_choice(bool *dq, bool *sq, int *index, char c);
int						open_quote(t_data *data, char *line);

char					*get_dollar_word(char *line, int size);
int						add_dollar(char *line, int *index, char **str,
							t_data *data);
int						add_char(char *c, char **str, t_data *data, int *index);
int						replace_dollar(char **line, t_data *data);
int						here_doc(t_data *data, char *word);

#endif
