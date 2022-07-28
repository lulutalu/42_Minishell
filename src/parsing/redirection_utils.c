//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"

size_t t_redirection_input(const char *input, t_cell *cell, int token, size_t i)
{
	if (input[i] == token && input[i + 1] == token)
	{
		cell->token = D_RE_INPUT;
		cell->data = ft_strdup("<<");
		cell->start = i;
		cell->end = i + 2;
		return(i + 2);
	}
	else
	{
		cell->token = RE_INPUT;
		cell->data = ft_strdup("<");
		cell->start = i;
		cell->end = i + 1;
		return(i + 1);
	}
}

size_t t_redirection_output(const char *input, t_cell *cell, int token, size_t i)
{
	if (input[i] == token && input[i + 1] == token)
	{
		cell->token = D_RE_OUTPUT;
		cell->data = ft_strdup(">>");
		cell->start = i;
		cell->end = i + 2;
		return(i + 2);
	}
	else
	{
		cell->token = RE_OUTPUT;
		cell->data = ft_strdup(">");
		cell->start = i;
		cell->end = i + 1;
		return(i + 1);
	}
}
