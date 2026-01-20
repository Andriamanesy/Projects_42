/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:11:12 by briandri          #+#    #+#             */
/*   Updated: 2026/01/17 13:57:34 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	read_in_stdin(t_data *data, int fd, char *word, char *file)
{
	char	*buf;

	signal(SIGINT, heredoc_sigint);
	while (1)
	{
		buf = readline("> ");
		if (g_signal_pid == SIGINT)
			break ;
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
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		free(buf);
	}
	close(fd);
	free(file);
	free_all(data, NULL, 0);
}

static int	wait_heredoc(t_data *data, int fd, char *word, char *file)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		close(fd);
		return (-1);
	}
	if (pid == 0)
		read_in_stdin(data, fd, word, file);
	signal(SIGINT, other_sigint);
	waitpid(pid, &status, 0);
	close(fd);
	if (g_signal_pid == SIGINT)
	{
		data->exit_code = 130;
		data->attr_error = 1;
	}
	return (status);
}

int	here_doc(t_data *data, char *word)
{
	int		fd;
	int		status;
	char	*file;
	char	*tmp;

	file = ft_strdup(".heredoc.tmp");
	while (access(file, F_OK) == 0)
	{
		tmp = file;
		file = ft_strjoin(file, "_copy");
		free(tmp);
	}
	unlink(file);
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	status = wait_heredoc(data, fd, word, file);
	if (status == -1)
		return (close(fd), -1);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		return (close(fd), unlink(file), -1);
	fd = open(file, O_RDONLY);
	unlink(file);
	free(file);
	return (fd);
}
