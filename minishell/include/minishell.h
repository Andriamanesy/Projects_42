/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:08:22 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 13:38:27 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "builtins.h"
# include "debug.h"
# include "env.h"
# include "executor.h"
# include "expander.h"
# include "lexer.h"
# include "parser.h"
# include "signals.h"
# include "utils.h"
# include <fcntl.h>
// # include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
// # include <stdbool.h>
// # include <stdio.h>
// # include <stdlib.h>
# include <sys/stat.h>
// # include <sys/types.h>
# include <sys/wait.h>

# define INPUT 1
# define HEREDOC 2
# define TRUNC 3
# define APPEND 4
# define PIPE 5
# define CMD 6
# define ARG 7

# define ERR_MALLOC "malloc error\n"
# define ERR_PIPE "pipe error\n"
# define ERR_FORK "fork error\n"

# define EXT_MALLOC 1
# define EXT_PIPE 1
# define EXT_FORK 1

extern pid_t			g_signal_pid;

typedef struct s_mlist	t_mlist;
typedef struct s_cmd	t_cmd;
typedef struct s_token	t_token;
typedef struct s_data	t_data;

typedef struct s_cmd
{
	bool				skip_cmd;
	int					infile;
	int					outfile;
	char				**cmd_param;
	bool				redir_error;
	struct s_cmd		*prev;
	struct s_cmd		*next;
}						t_cmd;

typedef struct s_token
{
	char				*str;
	int					type;
	struct s_token		*prev;
	struct s_token		*next;
}						t_token;

typedef struct s_mlist
{
	char				*content;
	struct s_mlist		*prev;
	struct s_mlist		*next;
}						t_mlist;

typedef struct s_data
{
	t_mlist				*env;
	t_token				*token;
	t_cmd				*cmd;
	int					exit_code;
	int					pip[2];
	bool				sq;
}						t_data;

void					init_data(t_data *data, int argc, char **argv);

#endif
