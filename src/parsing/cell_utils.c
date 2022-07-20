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
	return(quote);
}

t_cell	*init_cell(void)
{
	t_cell	*cell;

	cell = (t_cell *)malloc(sizeof(t_cell));
	if (!cell)
		return(NULL);
	cell->next = NULL;
	cell->prev = NULL;
	cell->quote = NULL;
	return(cell);
}

void connect_node(t_cell **node, t_cell **tmp, t_network **network)
{
	if ((*network)->head_cell == NULL)
	{
		(*node) = (*tmp);
		(*network)->head_cell = (*node);
	}
	else
	{
		(*node)->next = (*tmp);
		(*tmp)->prev = (*node);
		(*node) = (*node)->next;
	}
}
//
//t_cell	*set_node(t_cell **node, t_network **network, char *av)
//{
//	t_cell *tmp;
//
//	tmp = init_cell();
//	tmp->data = ft_strdup(av);
//	connect_node(node, &tmp, network);
//	//TODO set protect and return
//}

void	print_list(t_network *list)
{
	int		i;
	t_cell *tmp;

	tmp = list->head_cell;

	i = 0;
	printf("print list OK\n");
	while (tmp != NULL)
	{
		printf("print list running...\n");
		printf("-----------------------------------\n");
		printf("| i = %d                            \n", i);
		printf("| cell->cmd_sep : %s            \n", tmp->data);
		printf("| cell->token : %d            \n", tmp->token);

		printf("-----------------------------------\n");
		tmp = tmp->next;
		i++;
	}
}
