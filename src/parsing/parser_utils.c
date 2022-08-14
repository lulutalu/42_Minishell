/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:21:14 by lzima             #+#    #+#             */
/*   Updated: 2022/08/13 18:21:23 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

void free_str(char *s)
{
	if (!s)
	{
		free(s);
		s = NULL;
	}
}

void	check_last(t_main *m)
{
	char	*check;
	int		i;

	if (m->list.tail_cell)
	{
		check = m->list.tail_cell->data;
		i = 0;
		while ((check[i] == SPACE || check[i] == '\t') && check[i] != '\0')
			i++;
		if (check[i] == '\0')
		{
			if (m->list.tail_cell->prev != NULL)
			{
				m->list.tail_cell = m->list.tail_cell->prev;
				free_cell(m->list.tail_cell->next);
				m->list.tail_cell->next = NULL;
			}
			else
			{
				free_cell(m->list.tail_cell);
				m->list.head_cell = NULL;
			}
		}
	}
}

void	free_quote(t_quote *quote)
{

	free_str(quote->data_quote);
	free_str(quote->dollar_var);
	free(quote);
	quote = NULL;
}

void	free_cell(t_cell *cell)
{

	free_str(cell->data);
	free_str(cell->dollar_var);
	ft_tab_free((void *)cell->dollar_material);
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
