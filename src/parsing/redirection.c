//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"

int t_redirection_input(const char *input, t_cell *cell)
{
	int i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == S_TO_BIG)
		{
			cell->token = RE_INPUT;
			cell->data = ft_strdup("<");
			cell->pos = i;
		}
		if (input[i] && input[i + 1] == S_TO_BIG)
		{
			cell->token = D_RE_INPUT;
			cell->data = ft_strdup("<<");
			cell->pos = i;
		}
	}
	return(0);
}

int t_redirection_output(const char *input, t_cell *cell)
{
	int	i;

	i = -1;
	while(input[++i])
	{
		if (input[i] == BIG_TO_S)
		{
			cell->token = RE_OUTPUT;
			cell->data = ft_strdup(">");
			cell->pos = i;
		}
		if (input[i] && input[i + 1] == BIG_TO_S)
		{
			cell->token = D_RE_OUTPUT;
			cell->data = ft_strdup(">>");
			cell->pos = i;
		}
	}
	return(0);
}

void	redirection_parsing(char *input, t_cell *cell)
{
	t_redirection_input(input, cell);
	t_redirection_output(input, cell);
}