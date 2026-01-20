/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:53:48 by briandri          #+#    #+#             */
/*   Updated: 2026/01/17 13:57:51 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	heredoc_sigint(int code)
{
	(void)code;
	write(1, "\n", 1);
	g_signal_pid = code;
	close(0);
}

void	other_sigint(int code)
{
	(void)code;
	g_signal_pid = SIGINT;
}

void	heredoc_eof_warning(char *word)
{
	print_error("warning: here-document delimited by end-of-file ");
	print_error("(wanted `");
	print_error(word);
	print_error("')\n");
}
