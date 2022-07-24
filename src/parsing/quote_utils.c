//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"



int	stock_quote_data(const char *input, t_quote *quote, size_t end, int type) {
	size_t len;

	len = end - (quote->start + 1);
	if (len <= 0)
		quote->data_quote = ft_strdup("");
	quote->data_quote = ft_substr(input, (quote->start + 1), len);
	return (type);
}

int	second_quote_check_by_type_quote(t_cell *cell, int type, size_t i)
{
	size_t len;

	len = ft_strlen(cell->ret);
	cell->quote->start = i;
	while (i < len)
	{
		i++;
		if (cell->ret[i] == type)
		{
			cell->end = i;
			stock_quote_data(cell->ret, cell->quote, i, type);
			return (type);
		}
	}
	return (0);
}

char	*quote_saving(t_cell *cell, int token, size_t i)
{
	cell->quote = init_quote();
	token = second_quote_check_by_type_quote(cell, token, i);
	if (token == 0)
		error_message("Error pair: quote missing\n");
	cell->token = token;
	cell->pos = i;
	cell->data = ft_strdup(cell->quote->data_quote);
	cell->ret = ft_strreplace(cell->ret, "", (char)token);
	return(cell->ret);
}

char *pipe_saving(t_cell *cell, int token, size_t i)
{
	cell->token = token;
	cell->pos = i;
	cell->data = ft_strdup("|");
	cell->ret = ft_strreplace_one_trigger(cell->ret, "", (char)token);
	return (cell->ret);
}
char	*check_saving(const char *input, t_cell *cell)
{
	size_t i;
	size_t len;
	cell->ret = (char *) input;
	len = ft_strlen(input);

	i = 0;
	while (i < len) {
		while (input[i] == SPACE)
			i++;
		printf("input: %s\n i = %zu\n", input, i);
		if (input[i] == S_QUOTE)
			return(quote_saving(cell, S_QUOTE, i));
		else if (input[i] == D_QUOTE)
			return(quote_saving(cell, D_QUOTE, i));
		else if (input[i] == PIPE)
			return(pipe_saving(cell, PIPE, i));
		else if (input[i] == S_TO_BIG)
			return(t_redirection_input(input, cell, S_TO_BIG, i));
		else if (input[i] == BIG_TO_S)
			return(t_redirection_output(input, cell, BIG_TO_S, i));
		else if (input[i] == ft_isalpha(input[i]))
			return(cmd_saving(input, cell, i));
//		else if (input[i] == DOLLAR)
//			return(data_saved_in_cell(cell, DOLLAR));
		i++;
	}
	if (input[i] == '\0')
		cell->ret = NULL;
	printf("cell->ret = %s\n", cell->ret);
	return(cell->ret);
}

