/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:26 by briandri          #+#    #+#             */
/*   Updated: 2025/12/23 23:05:44 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stddef.h>

typedef struct s_data	t_data;
typedef struct s_token	t_token;
typedef struct s_cmd	t_cmd;

char					**get_param(t_data *data, t_token *token);

int						get_infile(t_data *data, t_token *token, t_cmd *cmd);
int						get_outfile(t_token *token, t_cmd *cmd, t_data *data);

int						append_cmd(t_cmd **list, int infile, int outfile,
							char **cmd_param);
void					free_cmd(t_cmd **list);
size_t					len_cmd(t_cmd *list);
int						check_pipe(t_data *data);
int						parseline(t_data *data, char *line);

#endif
