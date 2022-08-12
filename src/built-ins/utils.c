/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:12:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/12 17:28:46 by lduboulo         ###   ########.fr       */
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
