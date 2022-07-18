//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"
//
//char	**parser_pipe(char *input)
//{
//	t_cell *cell;
//	char *ret;
//	char **splitted;
//	int i;
//
//	(void)input;
//	cell = cell_mem_alloc();
//	if (!cell)
//		free_alloc(cell);
//	ret = quote(input, cell);
//	splitted = ft_split(ret, '|');
//	return (splitted);
//}


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



int main(int ac, char **av)
{
	char *input;
	char *ret;
	char *tmp;
	t_network *list;
	t_cell	*current_node;


	char input1[127] = "echo '12' \"103\"";
	char input2[127] = " OK";

	(void)ac;

/* only for test with main on parsing */
//	i = -1;
//	while(av[++i])
	input = ft_strjoin(input1, input2);

	(void)av;

	/* quote(input)
	 * 1 - stock what's inside "" or '' into cell->data
	 * 2 - and apply a token T_D_QUOTE or T_S_QUOTE in cell->token
	 * 3 - return a char *, with data replace by
	 * 									"S_QUOTE" or "D_QUOTE"
	 * 									echo "lol"
	 * 									echo T_D_QUOTE
	 *
	 * 									echo "lol" "lol2"
	 * 									echo T_D_QUOTE T_D_QUOTE
	 * 									*/
	printf("\n");
	printf("\n");
	printf("\n");
	printf("input: %s\n", input);

	list = init_network();
	list->head_cell = init_cell();
	list->head_cell->quote = init_quote();

	/*
	 *
	 quote

	split par |

	char **

	 1 cmd
	 2 args
	 3 redir
	 4 $ variable env
	 5

	*/
	current_node = list->head_cell;

	ret = input;
	while (1)
	{
		printf("ret: %s\n", ret);
		tmp = quote(ret, current_node);
		if (tmp == NULL)
		{
//			current_node->prev->next = NULL;
			free(current_node);
			current_node = NULL;
			break;
		}
		printf("tmp: %s\n", tmp);
		ret = tmp;
		current_node->next = init_cell();
		current_node->next->quote = init_quote();
		current_node = current_node->next;
		current_node->next = NULL;
//		printf("data: %s\n", current_node->data);
	}




//	ret2 = quote(ret, node);
//	printf("ret2: %s\n", ret2);



//	list = init_network();
//	i = 0;
//	while (++i < ac)
//	{
//
//	// TODO RETURN AND PROTECT
//	}
//	print_list(list);
	return (0);
}
