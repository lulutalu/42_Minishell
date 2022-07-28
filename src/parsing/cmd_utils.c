//
// Created by Lowell Zima on 7/24/22.
//

#include "./../../includes/minishell.h"
#include "parsing.h"
#include <fcntl.h>



size_t pipe_saving(t_cell *cell, int type, size_t i)
{
	cell->token = type;
	cell->start = i;
	cell->end = i + 1;
	cell->data = ft_strdup("|");
	return (cell->end);
}

size_t find_separators(const char *input, size_t i)
{
	while(input[i] != '\0')
	{
		if (input[i] == SPACE)
			return(i);
		if (input[i] == BIG_TO_S)
			return(i);
		if (input[i] == S_TO_BIG)
			return(i);
		if (input[i] == PIPE)
			return(i);
		i++;
	}
	return(i);
}

size_t cmd_saving(const char *input, size_t len, t_cell *cell, size_t i)
{
	size_t y;

	y = find_separators(input, i);
	cell->start = i;
	cell->data = ft_substr(input, i, (y - i));
	if (*cell->data == DOLLAR)
	{
		cell->dollar_material = ft_split(cell->data, '$');
		cell->token = T_DOLLAR;
	}
	if (cell->token != T_DOLLAR)
		cell->token = T_CMD;
	cell->end = ++y;
		return(y);
}
