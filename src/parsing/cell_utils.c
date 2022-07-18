//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"

int parser_main(char *input)
{
	t_cell	*cell;
	char	*ret;

	cell = cell_mem_alloc();
	if (!cell)
		free_alloc(cell);
	ret = quote(input, cell);
	redirection(ret, cell);
	cell->saved = ft_split(ret, ' ');
	return(0);
}