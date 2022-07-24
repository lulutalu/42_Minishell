//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"

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

t_network *set_network(t_network *list)
{
	list = init_network();
	list->head_cell = init_cell();
	list->current_cell = init_cell();
	list->current_cell = list->head_cell;
	return (list);
}

char *parser_main_quote(char *ret)
{
	char *saved_ret;
	t_network *list;

	list = NULL;
	list = set_network(list);
	ret = check_saving(ret, list->current_cell);
	while (ret != NULL)
	{
		list->current_cell->next = init_cell();
		list->current_cell = list->current_cell->next;
		list->tail_cell = list->current_cell;
		list->current_cell->next = NULL;
		saved_ret = ret;
		ret = check_saving(ret, list->current_cell);
		printf("ret after check_saving = %s\n", ret);
	}

	/* print for tests */
	printf("saved ret: %s\n", saved_ret);
	print_list(list);

	/* return */
	return (saved_ret);

	//TODO Protect ? Free after use
}

int main() {

	char *w_quote;

	/* input test from readline */
	char input[127] = "cd '-n' > \"$PATH\" | touch  'file1'  cat -e";
	printf("input: %s\n", input);


	w_quote = parser_main_quote(input);
}
