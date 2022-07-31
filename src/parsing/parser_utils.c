//
// Created by Lowell Zima on 6/1/22.
//

#include "./../../includes/minishell.h"





int	error_message(char *message)
{
	write(2, message, ft_strlen(message));
	return (0);
}

void	free_network(t_network *list)
{
	if (list->head_cell->quote != NULL)
	{
		if (list->head_cell->quote->data_quote != NULL)
			free(list->head_cell->quote->data_quote);
		if (list->head_cell->quote->tmp != NULL)
			free(list->head_cell->quote->tmp);
		free(list->head_cell->quote);
		list->head_cell->quote = NULL;
	}
	if (list->head_cell != NULL)
	{
		if (list->head_cell->data != NULL)
			free(list->head_cell->data);
		if (list->head_cell->next != NULL)
			free(list->head_cell->next);
		free(list->head_cell);
		list->head_cell = NULL;
	}
}

