/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:46:21 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/14 18:49:59 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cell_del(t_main *main, t_cell *cur)
{
	if (cur == main->list.tail_cell && cur->prev != NULL)
	{
		main->list.tail_cell = cur->prev;
		main->list.tail_cell->next = NULL;
	}
	else if (cur == main->list.head_cell && cur->next != NULL)
	{
		main->list.head_cell = cur->next;
		main->list.head_cell->prev = NULL;
	}
	else if (cur->prev != NULL && cur->next != NULL)
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	}
	else if (cur == main->list.tail_cell && cur == main->list.head_cell)
	{
		main->list.head_cell = NULL;
		main->list.tail_cell = NULL;
	}
	free_cell(cur);
	free(cur);
}

void	free_cell_list(t_main *main)
{
	t_cell	*cur;

	printf("%lu\n", sizeof(t_cell));
	cur = main->list.head_cell;
	if (cur)
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
			cell_del(main, cur->prev);
		}
		cell_del(main, cur);
	}
}

void	reset_cmd(t_main *main)
{
	to_be_free((void *)&main->restore_prompt);
	to_be_free((void *)&main->prompt);
	to_be_free((void *)&main->input);
	to_be_free((void *)&main->proc.pid);
	free_cell_list(main);
}

void	to_be_free(void **s)
{
	if ((*s) != NULL)
	{
		free(*s);
		(*s) = NULL;
	}
}
