/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 07:38:49 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 18:09:46 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

pid_t		g_signal_pid = 0;

static void	loop_body(t_data *data, char *line)
{
	if (g_signal_pid == SIGINT && data->exit_code < 128)
	{
		data->exit_code = 130;
		g_signal_pid = 0;
	}
	if (!line)
		free_all(data, "exit\n", data->exit_code);
	if (empty_line(line))
		return ;
	add_history(line);
	if (!parseline(data, line))
		return ;
	update_last_underscore(data, data->cmd);
	if (!exec(data))
		free_all(data, ERR_PIPE, EXT_PIPE);
	free_cmd(&data->cmd);
	free_token(&data->token);
	g_signal_pid = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_data			data;
	char			*line;
	int				fd;
	struct termios	t;

	init_data(&data, argc, argv);
	if (!make_env(&data, env))
		free_all(&data, ERR_MALLOC, EXT_MALLOC);
	while (1)
	{
		signals();
		data.attr_error = 0;
		fd = open("/dev/tty", O_RDWR);
		tcgetattr(fd, &t);
		close(fd);
		line = readline("minishell> ");
		loop_body(&data, line);
		fd = open("/dev/tty", O_RDWR);
		tcsetattr(fd, TCSANOW, &t);
		close(fd);
	}
	rl_clear_history();
	free_all(&data, NULL, data.exit_code);
	close(fd);
	return (data.exit_code);
}
