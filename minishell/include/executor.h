/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:13 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 02:37:31 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

typedef struct s_data	t_data;
typedef struct s_cmd	t_cmd;
typedef struct s_mlist	t_mlist;

int						exec(t_data *data);
void					child_process(t_data *data, t_cmd *cmd, int *pip);
char					*find_cmd(t_data *data, char *sample, t_mlist *env);
int						is_builtin(char *cmd);
int						launch_builtin(t_data *data, t_cmd *cmd);

char					*create_paths(t_mlist *env, int len);

#endif
