//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"

char *t_redirection_input(const char *input, t_cell *cell, int token, size_t i)
{
	if (input[i] == token && input[i + 1] == token)
	{
		cell->token = D_RE_INPUT;
		cell->data = ft_strdup("<<");
		cell->pos = i;
		cell->ret = ft_strreplace(cell->ret, "D_RE_INPUT", S_TO_BIG);

	}
	else
	{
		cell->token = RE_INPUT;
		cell->data = ft_strdup("<");
		cell->pos = i;
		cell->ret = ft_strreplace_one_trigger(cell->ret, "RE_INPUT", S_TO_BIG);
	}
	return(cell->ret);
}

char *t_redirection_output(const char *input, t_cell *cell, int token, size_t i)
{
	if (input[i] == token && input[i + 1] == token)
	{
		cell->token = D_RE_OUTPUT;
		cell->data = ft_strdup(">>");
		cell->pos = i;
		cell->ret = ft_strreplace_one_trigger(cell->ret, "RE_OUTPUT", BIG_TO_S);

	}
	else
	{
		cell->token = RE_OUTPUT;
		cell->data = ft_strdup(">");
		cell->pos = i;
		cell->ret = ft_strreplace_one_trigger(cell->ret, "RE_OUTPUT", BIG_TO_S);
	}
	return(cell->ret);
}
