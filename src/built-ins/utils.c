/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:12:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/11 20:19:38 by lduboulo         ###   ########.fr       */
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
	while (cur != NULL && cur->pos == icmd && cur->token != 999)
	{
		if (cur->token != 999 && cur->token != 36)
		{
			cur = cur->next->next;
			continue ;
		}
		cur = cur->next;
	}
	return (cur);
}
