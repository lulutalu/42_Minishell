/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:16:24 by lzima             #+#    #+#             */
/*   Updated: 2022/08/13 17:53:03 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

size_t	pipe_saving(t_cell *cell, int type, size_t i)
{
	cell->token = type;
	cell->start = i;
	cell->end = i + 1;
	cell->data = ft_strdup("|");
	return (cell->end);
}

size_t	find_separators(const char *input, size_t i)
{
	while (input[i] != '\0')
	{
		if (input[i] == SPACE)
			return (i);
		if (input[i] == BIG_TO_S)
			return (i);
		if (input[i] == S_TO_BIG)
			return (i);
		if (input[i] == PIPE)
			return (i);
		if (input[i] == D_QUOTE)
			return (i);
		if (input[i] == S_QUOTE)
			return (i);
		if (input[i] == '\t')
			return (i);
		i++;
	}
	return (i);
}

void	dollar_data(t_cell *cell, t_main *main)
{
	int		i;
	int		y;
	char	*tmp;
	t_node	*cur;

	i = 0;
	while (cell->dollar_material[i] != NULL)
	{
		cur = find_var(main, cell->dollar_material[i]);
		if (cur != NULL)
		{
			cell->dollar_material[i] = ft_strdup(cur->value);
			cell->dollar_var = ft_strdup(cur->value);
		}
		else
			cell->dollar_material[i] = ft_strdup("");
		i++;
	}
	y = 0;
	tmp = ft_strdup("");
	while (y < i)
		tmp = ft_strjoin(tmp, cell->dollar_material[y++]);
	cell->data = tmp;
}

size_t	cmd_saving(const char *input, t_cell *cell, size_t i, t_main *main)
{
	size_t	y;
	int		hidden_dollar;

	y = find_separators(input, i);
	cell->start = i;
	cell->data = ft_substr(input, i, (y - i));
	cell->dollar_material = NULL;
	cell->token = T_CMD;
	if (cell->data[0] == DOLLAR)
	{
		cell->dollar_material = ft_split(cell->data, '$');
		dollar_data(cell, main);
		cell->token = T_DOLLAR;
	}
	else if (!(cell->prev == NULL || cell->prev->token == PIPE))
	{
		hidden_dollar = ft_strchr_int(cell->data, '$');
		if (hidden_dollar > 0 && hidden_dollar != (int)cell->start)
		{
			cell->data = ft_substr(cell->data, 0, hidden_dollar);
			y = cell->start + hidden_dollar;
		}
	}
	cell->end = y;
	return (cell->end);
}

void	cmd_listing(t_main *main)
{
	t_cell	*cur;

	main->proc.ncmd = 1;
	cur = main->list.head_cell;
	while (cur != NULL)
	{
		cur->pos = main->proc.ncmd;
		if (cur->token == PIPE)
		{
			cur->pos = 0;
			main->proc.ncmd++;
		}
		cur = cur->next;
	}
}
