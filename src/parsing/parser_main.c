//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"

int	ft_isprint_without_space(int c)
{
	if (c >= 33 && c <= 126)
		return (c);
	else
		return (0);
}

size_t	reader(const char *input, t_cell *cell, size_t i, size_t len)
{
	while (i < len)
	{
		while (input[i] == SPACE)
			i++;
		if (input[i] == S_QUOTE || input[i] == D_QUOTE)
			return(quote_saving(input, len, cell, i));
		else if (input[i] == PIPE)
			return(pipe_saving(cell, PIPE, i));
		else if (input[i] == S_TO_BIG)
			return(t_redirection_input(input, cell, S_TO_BIG, i));
		else if (input[i] == BIG_TO_S)
			return(t_redirection_output(input, cell, BIG_TO_S, i));
		else if (input[i] == ft_isprint_without_space(input[i]))
			return(cmd_saving(input, len, cell, i));
		i++;
	}
	return(i);
}

void parser_main_quote(char *ret)
{
	t_network *list;
	static size_t i;
	size_t len;

	len = ft_strlen(ret);
	list = set_network();
	i = 0;
	while (i < len)
	{
		i = reader(ret, list->current_cell, i, len);
		list->current_cell = add_node(list);
	}

	//print for tests
	printf("print prepared OK\n");
	print_list(list);
}


void	print_list(t_network *list) {
	int i;
	t_cell *tmp;

	tmp = list->head_cell;

	i = 0;
	printf("print list OK\n");
	while (tmp->next != NULL) {
		printf("print list running...\n");
		printf("-----------------------------------	\n");
		printf("| Start = %zu                   	\n", tmp->start);
		printf("| End = %zu                    		\n", tmp->end);
		printf("| cell->data : %s               	\n", tmp->data);
		printf("| cell->token : %d                 	\n", tmp->token);
		if (tmp->dollar_material)
			printf("| cell->dollar_material : %s     \n", tmp->dollar_material[0]);
		printf("-----------------------------------	\n");
		tmp = tmp->next;
		i++;
	}
}

int main()
{
	char *input = " 1 '2' 3 \"d_q\" |3 > >> < << fin ";
	parser_main_quote(input);
}
