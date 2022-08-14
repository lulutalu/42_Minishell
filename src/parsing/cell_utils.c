/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:47:00 by lzima             #+#    #+#             */
/*   Updated: 2022/08/14 18:48:43 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

t_quote	*init_quote(void)
{
	t_quote	*quote;

	quote = ft_calloc(1, sizeof(t_quote));
	alloc_check(quote);
	quote->dollar_var = NULL;
	return (quote);
}

t_cell	*init_cell(void)
{
	t_cell	*cell;

	cell = ft_calloc(1, sizeof(t_cell));
	alloc_check(cell);
	cell->next = NULL;
	cell->prev = NULL;
	cell->quote = NULL;
	cell->dollar_var = NULL;
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
