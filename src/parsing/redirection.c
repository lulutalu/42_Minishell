//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"

int parser_main(char *input)
{
	t_cell	*cell;

	cell = cell_mem_alloc();
	if (!cell)
		free_alloc(e);
	quote(input, cell);
	redirection(input, cell);
	return(0);
}