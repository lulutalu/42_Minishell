/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:21:14 by lzima             #+#    #+#             */
/*   Updated: 2022/08/06 12:21:22 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

int	error_message(char *message)
{
	write(2, message, ft_strlen(message));
	return (0);
}

void	free_quote(t_quote *quote)
{
	if (quote->data_quote != NULL)
	{
		free(quote->data_quote);
		quote->data_quote = NULL;
	}
	free(quote);
	quote = NULL;
}

void	free_cell(t_cell *cell)
{
	int	i;

	if (cell->data != NULL)
	{
		free(cell->data);
		cell->data = NULL;
	}
	i = -1;
	while (cell->dollar_material[++i] != NULL)
		free(cell->dollar_material[i]);
}
