//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"


int	message(char *message)
{
	write(2, message, ft_strlen(message));
	return (1);
}

void	error_message(char *message)
{
	perror(message);
	exit(1);
}

int	stock_quote_data(char *input, s_quote quote, int i)
{
	int len;
	char **temp;

	len = quote->end - quote->start;
	if (len == 0)
		quote->data = ft_substr("");
	quote->data = ft_dyn_substr(input, (quote->start + 1), len - 1);
}

int check_quote(char *input, s_quote quote)
{
	int i;
	int pair;

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
				}
			}
			if (pair != 2)
				error_message("Error pair: quote missing\n")
		}
	}
	return(0);
}
