/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:47:00 by lzima             #+#    #+#             */
/*   Updated: 2022/08/13 15:30:21 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

t_quote	*init_quote(void)
{
	t_quote	*quote;

	quote = ft_calloc(1, sizeof(t_quote));
	if (!quote)
		return (NULL);
	quote->tmp = NULL;
	quote->dollar_var = NULL;
	return (quote);
}

t_cell	*init_cell(void)
{
	t_cell	*cell;

	cell = ft_calloc(1, sizeof(t_cell));
	if (!cell)
		return (NULL);
	cell->next = NULL;
	cell->prev = NULL;
	cell->quote = NULL;
	return (cell);
}

t_network	init_network(void)
{
	t_network	ptr;

	ptr.head_cell = NULL;
	ptr.tail_cell = NULL;
	ptr.current_cell = NULL;
	return (ptr);
}

t_network	set_network(void)
{
	t_network	list;

	list = init_network();
	list.head_cell = list.current_cell;
	list.tail_cell = list.current_cell;
	return (list);
}

t_cell	*add_node(t_network *list)
{
	t_cell	*cur;

	cur = init_cell();
	if (list->head_cell == NULL)
	{
		list->head_cell = cur;
		list->tail_cell = cur;
		list->current_cell = cur;
	}
	else
	{
		list->tail_cell->next = cur;
		cur->prev = list->tail_cell;
		list->current_cell = cur;
		list->tail_cell = cur;
	}
	return (list->current_cell);
}
