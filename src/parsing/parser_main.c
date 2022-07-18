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



int main() {
	char *input;
	char *ret;
	t_network *list;
	t_cell *current_node;


	char input1[127] = "echo ''1'' '2' \"103\" '123'";
	char input2[127] = " OK";


/* only for test with main on parsing */
	input = ft_strjoin(input1, input2);
	list = init_network();
	list->head_cell = init_cell();
	list->head_cell->quote = init_quote();

	current_node = list->head_cell;
	current_node->data = NULL;
	ret = input;
	char *saved_ret;
	ret = quote_saving(ret, current_node);
	while (ret != NULL) {
		current_node->next = init_cell();
		current_node->next->quote = init_quote();
		current_node = current_node->next;
		current_node->next = NULL;
		saved_ret = ret;
		ret = quote_saving(ret, current_node);
	}
	printf("saved ret: %s\n", saved_ret);
	print_list(list);
	free(current_node);
	current_node = NULL;
	return (0);
}
