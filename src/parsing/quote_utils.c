/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:54:47 by lzima             #+#    #+#             */
/*   Updated: 2022/08/12 23:48:22 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

void	quote_data(char *input, t_quote *quote, t_main *main, size_t end)
{
	size_t	len;
	char	*ret;

	len = end - (quote->start + 1);
	if (len <= 0)
		quote->data_quote = ft_strdup("");
	quote->data_quote = ft_substr(input, (quote->start + 1), len);
	if (quote->type == D_QUOTE)
	{
		ret = is_dollar_in_d_quote(quote, main);
		while (ret != NULL)
		{
			quote->data_quote = ret;
			ret = is_dollar_in_d_quote(quote, main);
		}
	}
}

size_t	check_by_type(char *input, t_cell *cell, t_main *main, int type)
{
	size_t	len;

	cell->quote->type = type;
	cell->quote->i = cell->quote->start;
	len = ft_strlen(input);
	while (cell->quote->i < len)
	{
		cell->quote->i++;
		if (input[cell->quote->i] == type)
		{
			quote_data(input, cell->quote, main, cell->quote->i);
			return (cell->quote->i + 1);
		}
		if (input[cell->quote->i] == '\0')
		{
			cell->quote->error = 1;
			return (len);
		}
	}
	return (0);
}

size_t	quote_saving(char *input, t_cell *cell, t_main *main, size_t i)
{
	cell->dollar_material = NULL;
	cell->quote = init_quote();
	if (input[i] == S_QUOTE)
		cell->type = S_QUOTE;
	else
		cell->type = D_QUOTE;
	cell->start = i;
	cell->token = cell->type;
	cell->quote->start = i;
	cell->quote->error = 0;
	cell->end = check_by_type(input, cell, main, cell->type);
	cell->error = cell->quote->error;
	cell->data = ft_strdup(cell->quote->data_quote);
	free_quote(cell->quote);
	return (cell->end);
}
