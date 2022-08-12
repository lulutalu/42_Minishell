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

void check_last(t_main *m)
{
	char	*check;
	int		i;

	check = m->list.current_cell->data;
	i = 0;
	while (check[i] == SPACE || check[i] == '\t' || check[i] != '\0')
		i++;
	if (check[i] != SPACE || check[i] != '\t')
	{
		m->list.tail_cell = m->list.current_cell->prev;
		m->list.tail_cell->next = NULL;
		free_cell(m->list.current_cell);
	}
}

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

int	ft_strchr_int(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (i);
	else
		return (-1);
}
