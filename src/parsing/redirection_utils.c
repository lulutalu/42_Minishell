/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:28:42 by lzima             #+#    #+#             */
/*   Updated: 2022/08/12 23:35:42 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

size_t	t_re_input(const char *input, t_cell *cell, int token, size_t i)
{
	if (input[i] == token && input[i + 1] == token)
	{
		cell->token = D_RE_INPUT;
		cell->data = ft_strdup("<<");
		cell->start = i;
		cell->end = i + 2;
		return (i + 2);
	}
	else
	{
		cell->token = RE_INPUT;
		cell->data = ft_strdup("<");
		cell->start = i;
		cell->end = i + 1;
		return (i + 1);
	}
}

size_t	t_re_output(const char *input, t_cell *cell, int token, size_t i)
{
	if (input[i] == token && input[i + 1] == token)
	{
		cell->token = D_RE_OUTPUT;
		cell->data = ft_strdup(">>");
		cell->start = i;
		cell->end = i + 2;
		return (i + 2);
	}
	else
	{
		cell->token = RE_OUTPUT;
		cell->data = ft_strdup(">");
		cell->start = i;
		cell->end = i + 1;
		return (i + 1);
	}
}
