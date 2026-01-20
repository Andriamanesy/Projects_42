/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:13 by briandri          #+#    #+#             */
/*   Updated: 2026/01/20 10:44:06 by briandri         ###   ########.fr       */
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
int						check_dir(char **path, char *cmd, t_data *data);
void					print_not_found(t_data *data, char *cmd);
void					cmd_not_exist(char **path, char *cmd);
int						check_cmd(t_data *data, char *cmd);
int						cmd_exist(char **path, t_data *data, char *cmd);
int						handle_exec_special_cases(t_data *data, t_cmd *tmp);
int						exec_pipeline(t_data *data, t_cmd *tmp, int *pip);
pid_t					exec_cmd(t_data *data, t_cmd *cmd, int *pip);
void					wait_all(t_data *data, pid_t p);

#endif
