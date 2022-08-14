/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:21:14 by lzima             #+#    #+#             */
/*   Updated: 2022/08/14 18:50:31 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

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
			cell_del(m, m->list.tail_cell);
	}
}

void	free_quote(t_quote *quote)
{
	to_be_free((void *)&quote->data_quote);
	to_be_free((void *)&quote->dollar_var);
	free(quote);
	quote = NULL;
}

void	free_cell(t_cell *cell)
{
	to_be_free((void *)&cell->data);
	to_be_free((void *)&cell->dollar_var);
	ft_tab_free((void **)cell->dollar_material);
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
