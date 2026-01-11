/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:11:12 by briandri          #+#    #+#             */
/*   Updated: 2025/12/29 13:07:14 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	heredoc_sigint(int code)
{
	(void)code;
	write(1, "\n", 1);
	exit(130);
}

static void	other_sigint(int code)
{
	(void)code;
	g_signal_pid = SIGINT;
	clear_rl_line();
}

static void	heredoc_eof_warning(char *word)
{
	print_error("warning: here-document delimited by end-of-file ");
	print_error("(wanted `");
	print_error(word);
	print_error("')\n");
}

static void	read_in_stdin(t_data *data, int fd, char *word)
{
	char	*buf;

	signal(SIGINT, heredoc_sigint);
	while (1)
	{
		buf = readline("> ");
		if (!buf)
		{
			heredoc_eof_warning(word);
			break ;
		}
		if (!ft_strcmp(buf, word))
		{
			free(buf);
			break ;
		}
		if (!replace_dollar(&buf, data))
			exit(1);
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		free(buf);
	}
	close(fd);
	exit(0);
}

int	here_doc(t_data *data, char *word)
{
	int		fd;
	pid_t	pid;
	int		status;

	unlink(".heredoc.tmp");
	fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (close(fd), -1);
	if (pid == 0)
		read_in_stdin(data, fd, word);
	signal(SIGINT, other_sigint);
	waitpid(pid, &status, 0);
	close(fd);
	if (g_signal_pid == SIGINT)
		data->exit_code = 130;
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		unlink(".heredoc.tmp");
		return (-1);
	}
	fd = open(".heredoc.tmp", O_RDONLY);
	unlink(".heredoc.tmp");
	return (fd);
}
