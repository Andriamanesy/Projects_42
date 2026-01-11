/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:11:16 by briandri          #+#    #+#             */
/*   Updated: 2026/01/11 13:50:39 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int  open_file(t_data *data, char *filename, int type)
{
    int fd;

    fd = -2;
    if (type == INPUT)
        fd = open(filename, O_RDONLY, 0644);
    else if (type == HEREDOC)
        fd = here_doc(data, filename);
    else if (type == TRUNC)
        fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    else if (type == APPEND)
        fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (type != HEREDOC && fd < 0)
        perror(filename);
    return (fd);
}

static int  get_in(t_data *data, t_token *tmp, t_cmd *cmd)
{
    int type;

    if (tmp->type == INPUT || tmp->type == HEREDOC)
    {
		if (cmd->infile >= 0)
            close(cmd->infile);
        if (tmp->next == data->token || tmp->next->type == PIPE || tmp->next->type <= 5)
        {
            // CETTE CONDITION EST LA SEULE QUI EMPECHE LE DOUBLE AFFICHAGE
            if (cmd->redir_error == false)
                ft_putendl_fd("minishell: ambiguous redirect", 2);
            cmd->redir_error = true;
            return (1);
        }
        type = (tmp->type == INPUT) ? INPUT : HEREDOC;
        if (cmd->redir_error == false)
        {
            cmd->infile = open_file(data, tmp->next->str, type);
            if (cmd->infile == -1)
                cmd->redir_error = true;
        }
    }
    return (1);
}

int get_infile(t_data *data, t_token *token, t_cmd *cmd)
{
    t_token *tmp;

    tmp = token;
    if (tmp->type != PIPE && !get_in(data, tmp, cmd))
        return (0);
    if (tmp->type == PIPE)
        return (1);
    tmp = tmp->next;
    while (tmp->type != PIPE && tmp != data->token)
    {
        if (!get_in(data, tmp, cmd))
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

static int  get_out(t_token *tmp, t_cmd *cmd, t_data *data)
{
    if (tmp->type == TRUNC || tmp->type == APPEND)
    {
        if (cmd->outfile >= 0)
            close(cmd->outfile);
        if (tmp->next == data->token || tmp->next->type == PIPE || tmp->next->type <= 5)
        {
            if (cmd->redir_error == false)
                ft_putendl_fd("minishell: ambiguous redirect", 2);
            cmd->redir_error = true;
            return (1);
        }
        if (cmd->redir_error == false)
        {
            cmd->outfile = open_file(NULL, tmp->next->str, tmp->type);
            if (cmd->outfile == -1)
                cmd->redir_error = true;
        }
    }
    return (1);
}

int get_outfile(t_token *token, t_cmd *cmd, t_data *data)
{
    t_token *tmp;

    tmp = token;
    if (tmp->type != PIPE && !get_out(tmp, cmd, data))
        return (0);
    tmp = tmp->next;
    while (tmp != data->token && tmp->type != PIPE)
    {
        if (!get_out(tmp, cmd, data))
            return (0);
        tmp = tmp->next;
    }
    return (1);
}
