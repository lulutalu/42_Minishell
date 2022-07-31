//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"

void	stock_quote_data(const char *input, t_quote *quote, size_t end, int type)
{
	size_t len;

	(void)type;
	len = end - (quote->start + 1);
	if (len <= 0)
		quote->data_quote = ft_strdup("");
	quote->data_quote = ft_substr(input, (quote->start + 1), len);
}

size_t	check_by_type_quote(const char *input, t_cell *cell, int type)
{
	size_t len;

	cell->quote->i = cell->quote->start;
	len = ft_strlen(input);
	while (cell->quote->i < len)
	{
		cell->quote->i++;
		if (input[cell->quote->i] == type)
		{
			stock_quote_data(input, cell->quote, cell->quote->i, type);
			return (cell->quote->i + 1);
		}
		if (input[cell->quote->i] == '\0')
		{
			error_message("Error pair: cell->quote missing\n");
			return(len);
		}
	}
	return (0);
}

size_t	quote_saving(const char *input, size_t len, t_cell *cell, size_t i)
{
	(void)len;
	cell->quote = init_quote();
	if (input[i] == S_QUOTE)
		cell->type = S_QUOTE;
	else
		cell->type = D_QUOTE;
	cell->start = i;
	cell->token = cell->type;
	cell->quote->start = i;
	cell->end = check_by_type_quote(input, cell, cell->type);
	cell->data = ft_strdup(cell->quote->data_quote);
	return(cell->end);
}


