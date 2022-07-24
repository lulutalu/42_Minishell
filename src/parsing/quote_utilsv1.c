//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"



int	stock_quote_data(const char *input, t_quote *quote, size_t end, int type)
{
	size_t len;

	len = end - (quote->start + 1);
	if (len <= 0)
		quote->data_quote = ft_strdup("");
	quote->data_quote = ft_substr(input, (quote->start + 1), len);
	return(type);
}

int	second_quote_check_by_type_quote(const char *input, t_quote *quote, int type)
{
	size_t len;

	len = ft_strlen(input);
	quote->start = quote->i;
	while (quote->i < len)
	{
		quote->i++;
		if (input[quote->i] == type)
		{
			stock_quote_data(input, quote, quote->i, type);
			return (type);
		}
	}
	if (input[quote->i] == '\0')
		error_message("Error pair: quote missing\n");
	return (0);
}

int check_quote(const char *input, t_quote *quote, int quote_type)
{

	quote_type = check_by_type_quote(input, quote, quote_type);

	check_by_type_quote(input, quote, D_QUOTE);

	return(0);
}


//
//
//	if (check_quote(cell->quote->tmp, cell->quote) == S_QUOTE)
//		cell->quote->tmp = quote_saving(cell, S_QUOTE);
//	else if (check_quote(cell->quote->tmp, cell->quote) == D_QUOTE)
//		cell->quote->tmp = quote_saving(cell, D_QUOTE);
//
//
////	/*down date*/
//	else if (check_quote(cell->quote->tmp, cell->quote) == D_QUOTE)
//	{
//		cell->token = T_D_QUOTE;
//		cell->pos = cell->quote->start;
//		cell->data = ft_strdup(cell->quote->data_quote);
//		cell->quote->tmp = ft_strreplace(cell->quote->tmp, "D_QUOTE", D_QUOTE);
//	}
	else
		cell->quote->tmp = NULL;
	return (cell->quote->tmp);
}




int stock_quote_data(const char *input, t_quote *quote, size_t end, int type_quote)
{
	size_t len;

	len = end - (quote->start + 1);
	if (len <= 0)
		quote->data_quote = ft_strdup("");
	quote->data_quote = ft_substr(input, (quote->start + 1), len);
	return(type_quote);
}

int check_quote(const char *input, t_quote *quote, int s_quote, int d_quote, size_t i)
{
	while (++i < ft_strlen(input))
	{
		if (input[i] == s_quote)
		{
			while (i < ft_strlen(input))
			{
				quote->start = i;
				if (input[i++] == s_quote)
					return(stock_quote_data(input, quote, i - 1, s_quote));
			}
		}
		if (input[i] == d_quote)
		{
			while (i < ft_strlen(input))
			{
				quote->start = i;
				if (input[i++] == d_quote)
					return(stock_quote_data(input, quote, i - 1, d_quote));
			}
		}
		if (input[i] == '\0')
			error_message("Error pair: quote missing\n");
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

char	*quote_saving(const char *input, t_cell *cell)
{
	int i;

	i = -1;
	cell->data = NULL;
	cell->quote->tmp = (char *)input;
	if (check_quote(cell->quote->tmp, cell->quote, S_QUOTE, D_QUOTE, i) == S_QUOTE)
	{
		cell->token = T_S_QUOTE;
		cell->data = ft_strdup(cell->quote->data_quote);
		cell->quote->tmp = ft_strreplace(cell->quote->tmp, "S_QUOTE", S_QUOTE);

	}
	else if (check_quote(cell->quote->tmp, cell->quote, S_QUOTE, D_QUOTE, i) == D_QUOTE)
	{
		cell->token = T_D_QUOTE;
		cell->data = ft_strdup(cell->quote->data_quote);
		cell->quote->tmp = ft_strreplace(cell->quote->tmp, "D_QUOTE", D_QUOTE);
	}
	else
		cell->quote->tmp = NULL;
	return (cell->quote->tmp);
}
