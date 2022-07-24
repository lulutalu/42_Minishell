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
//	list->head_cell->quote = init_quote();
	ret = check_saving(ret, list->current_cell);
	while (ret != NULL)
	{
		list->current_cell->next = init_cell();
//		list->current_cell->next->quote = init_quote();
		list->current_cell = list->current_cell->next;
		list->tail_cell = list->current_cell;
		list->current_cell->next = NULL;
		saved_ret = ret;
		ret = check_saving(ret, list->current_cell);
	}

	/* print for tests */
	printf("saved ret: %s\n", saved_ret);
	print_list(list);

	/* return */
	return (saved_ret);

	//TODO Protect ? Free after use
}

//
//void parser_pipe(char *saved_ret)
//{
////	char **cmd_split_pipe;
//	char *ret;
////	int i;
//	t_network	*pipe_list;
//	t_cell		*current_node_pipe;
//
//	pipe_list = NULL;
//	current_node_pipe = NULL;
//	pipe_list = set_network(pipe_list);
//	ret = ft_strreplace(saved_ret, "PIPE", PIPE);
//
////	while(ret != NULL)
////	{
//		ret = ft_strreplace(saved_ret, "PIPE", PIPE);
//		printf("ret with PIPE: %s\n", ret);
//	}

//	cmd_split_pipe = ft_split(saved_ret, '|');
//	i = 0;
//	while(cmd_split_pipe[i] != NULL)
//	{
//		printf("cmd_split_pipe : %s\n", cmd_split_pipe[i++]);
//	}
//	return(cmd_split_pipe);
//}

int main()
{

	char *w_quote;
//	char **cmd_split_pipe;

/* input test from readline */
	char input[127] = "echo '-n' << < > \"$PATH\" | touch > 'file1'  cat -e";
	printf("input: %s\n", input);


	w_quote = parser_main_quote(input);
//	parser_pipe(w_quote);
//	cmd_split_pipe = parser_pipe(w_quote);
 }





/* only for test with main on parsing
int main() {
	char *input;
	char *ret;
	t_network *list;
	t_cell *current_node;


	char input1[127] = "echo ''1'' '2' \"103\" '123'";
	char input2[127] = " OK";


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
*/