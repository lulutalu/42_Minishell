/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:12:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/12 18:48:00 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*cmd_input(t_main *main)
{
	char	*input;

	if (main->input)
	{
		input = ft_strchr(main->input, ' ');
		input = ft_strdup(input + 1);
	}
	else
		input = ft_strdup("");
	return (input);
}

int	echo_protection(t_cell *cur)
{
	if (cur == NULL)
	{
		ft_putendl_fd("", STDOUT);
		return (0);
	}
	return (1);
}

void	echo_end_print(t_main *main)
{
	if (main->proc.ncmd == 1 && main->fd.outfile > 1)
		ft_putendl_fd("", main->fd.outfile);
	else
		ft_putendl_fd("", STDOUT);
}

t_cell	*avoid_redir(t_cell *cur, int icmd)
{
	while (cur != NULL && cur->pos != icmd)
		cur = cur->next;
	while (cur != NULL && cur->pos == icmd && cur->token != 999 && cur->token \
			!= DOLLAR && cur->token != S_QUOTE && cur->token != D_QUOTE)
	{
		if (cur->token != 999 && cur->token != 36 && cur->token != S_QUOTE \
				&& cur->token != D_QUOTE)
		{
			cur = cur->next->next;
			continue ;
		}
		cur = cur->next;
	}
	return (cur);
}
