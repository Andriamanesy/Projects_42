/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harramar <harramar@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 07:22:43 by harramar          #+#    #+#             */
/*   Updated: 2025/12/29 07:23:06 by harramar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

typedef struct s_token	t_token;
typedef struct s_cmd	t_cmd;

void					print_token(t_token *token);
void					print_tab(char **tab);
void					print_cmd(t_cmd *cmd);

#endif
