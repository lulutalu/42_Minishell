//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"

int	stock_quote_data(char *input, s_quote quote, int i)
{
	int len;
	char **temp;

	len = quote->end - quote->start;
	if (len == 0)
		quote->data = ft_substr("");
	quote->data = ft_dyn_substr(input, (quote->start + 1), len - 1);
}

int check_quote(char *input, s_quote quote, char quote_type)
{
	int i;
	int pair;

	quote->type = quote_type;
	i = -1;
	while (input[++i])
	{
		if (input[i] == quote->type)
		{
			pair = 1;
			quote->start = i;
			while (input[++i])
			{
				if (input[i] == quote->type)
				{
					pair = 2;
					quote->end = i;
					stock_quote_data(input, quote, i);
					return(1);
				}
			}
			if (pair != 2)
				error_message("Error pair: quote missing\n")
		}
	}
	return(0);
}

void	quote(char *input, t_cell *cell)
{
	if (check_quote(input, cell, S_QUOTE == 1))
	{
		cell->token = T_S_QUOTE;
		cell->data = ft_strdup(quote->data);
		cell->pos = quote->start;
	}
	if (check_quote(input, cell, D_QUOTE == 1))
	{
		cell->token = T_D_QUOTE;
		cell->data = ft_strdup(quote->data);
		cell->pos = quote->start;
	}
}
