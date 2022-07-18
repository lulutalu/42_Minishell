//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"

void	stock_quote_data(const char *input, t_quote *quote, int end)
{
	int len;

	len = end - (quote->start + 1);
	if (len <= 0)
		quote->data_quote = ft_strdup("");
	quote->data_quote = ft_substr(input, (quote->start + 1), len);
}

int check_quote(const char *input, t_quote *quote, int quote_type)
{
	size_t i;

	quote->type = quote_type;
	i = 0;
	while (i < ft_strlen(input))
	{
		if (input[i] == quote->type)
		{
			quote->start = i;
			while (i < ft_strlen(input))
			{
				i++;
				if (input[i] == quote->type)
				{
					stock_quote_data(input, quote, i);
					return (1);
				}
			}
			if (input[i] == '\0')
				error_message("Error pair: quote missing\n");
		}
		i++;
	}
	return(0);
}

void	free_quote(t_cell *cell)
{
	if (!cell->quote->data_quote)
		free(cell->quote->data_quote);
	if (cell->quote)
		free(cell->quote);
}

char	*quote(const char *input, t_cell *cell)
{
	char *ret;

	ret = NULL;
	if (check_quote(input, cell->quote, S_QUOTE) == 1)
	{
		cell->token = T_S_QUOTE;
		cell->data = ft_strdup(cell->quote->data_quote);
		printf("cell-data: %s \n token %d\n", cell->data, cell->token);
		ret = ft_strreplace(input, "S_QUOTE", S_QUOTE);
	}
	if (check_quote(input, cell->quote, D_QUOTE) == 1)
	{
		cell->token = T_D_QUOTE;
		cell->data = ft_strdup(cell->quote->data_quote);
		printf("cell-data: %s \n token %d\n", cell->data, cell->token);
		ret = ft_strreplace(input, "D_QUOTE", D_QUOTE);
	}
	return (ret);
}
