//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"

t_quote	*init_quote(void)
{
	t_quote *quote;

	quote = (t_quote *)malloc(sizeof(t_quote));
	if (!quote)
		return(NULL);
	quote->tmp = NULL;
	return(quote);
}

t_cell	*init_cell(void)
{
	t_cell	*cell;

	cell = (t_cell *)malloc(sizeof(t_cell));
	if (!cell)
		return(NULL);
	cell->next = NULL;
	cell->quote = NULL;
	return(cell);
}


t_network 	*init_network(void)
{
	t_network	*ptr;

	ptr = (t_network *)malloc(sizeof(t_network));
	if (!ptr)
		return (NULL);
	ptr->head_cell = NULL;
	ptr->tail_cell = NULL;
	return (ptr);
}

t_network *set_network()
{
	t_network *list;

	list = init_network();
	list->head_cell = init_cell();
	list->current_cell = init_cell();
	list->current_cell = list->head_cell;
	return (list);
}

t_cell	*add_node(t_network *list)
{
	list->current_cell->next = init_cell();
	list->current_cell = list->current_cell->next;
	list->tail_cell = list->current_cell;
	list->current_cell->next = NULL;
	return(list->tail_cell);
}
