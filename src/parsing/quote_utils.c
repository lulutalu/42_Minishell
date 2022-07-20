//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
<<<<<<< HEAD

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
=======
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
>>>>>>> 1cc483979b071f37bdfb04e9e63b5bb293e89ac7
	}
	return(0);
}

<<<<<<< HEAD
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
=======
void	free_quote(t_cell *cell)
{
	if (!cell->quote->data_quote)
		free(cell->quote->data_quote);
	if (cell->quote)
		free(cell->quote);
}

char	*quote_saving(const char *input, t_cell *cell)
{
	cell->data = NULL;
	cell->quote->tmp = (char *)input;
	if (check_quote(cell->quote->tmp, cell->quote, S_QUOTE) == 1)
	{
		cell->token = T_S_QUOTE;
		cell->data = ft_strdup(cell->quote->data_quote);
//		printf("cell->data: %s \n+ token %d\n", cell->data, cell->token);
		cell->quote->tmp = ft_strreplace(cell->quote->tmp, "S_QUOTE", S_QUOTE);
//		printf("cell->quote->tmp: %s \n+ token %d\n", cell->quote->tmp, cell->token);

	}
	else if (check_quote(cell->quote->tmp, cell->quote, D_QUOTE) == 1)
	{
		cell->token = T_D_QUOTE;
		cell->data = ft_strdup(cell->quote->data_quote);
//		printf("cell->data: %s \n+ token %d\n", cell->data, cell->token);
		cell->quote->tmp = ft_strreplace(cell->quote->tmp, "D_QUOTE", D_QUOTE);
//		printf("cell->quote->tmp: %s \n token %d\n", cell->quote->tmp, cell->token);

	}
	else
		cell->quote->tmp = NULL;
	return (cell->quote->tmp);
}


>>>>>>> 1cc483979b071f37bdfb04e9e63b5bb293e89ac7
