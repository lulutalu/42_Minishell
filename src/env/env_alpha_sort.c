/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_alpha_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:16:30 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/05 14:25:11 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_node	*find_next_temp(t_main *main)
{
	t_node	*temp;

	temp = main->head_env;
	while (temp != NULL && temp->sort_pos > 0)
		temp = temp->next;
	return (temp);
}

static void	sort_all_alphabetical(t_main *main, t_node *lowest)
{
	t_node	*cur;
	t_node	*temp;
	int		i;

	i = 2;
	while (i <= lst_size(main))
	{
		temp = find_next_temp(main);
		cur = temp->next;
		while (cur != NULL)
		{
			if (ft_strncmp(lowest->var, cur->var, 100) < 0 \
				&& ft_strncmp(temp->var, cur->var, 100) > 0)
				temp = cur;
			cur = cur->next;
		}
		temp->sort_pos = i++;
		lowest = temp;
	}
}

static void	sort_alphabetical(t_main *main)
{
	t_node	*cur;
	t_node	*temp;

	cur = main->head_env->next;
	temp = main->head_env;
	while (cur != NULL)
	{
		if (ft_strncmp(temp->var, cur->var, ft_strlen(temp->var)) > 0)
			temp = cur;
		cur = cur->next;
	}
	temp->sort_pos = 1;
	sort_all_alphabetical(main, temp);
}

static void	sort_reset(t_main *main)
{
	t_node	*cur;

	cur = main->head_env;
	while (cur != NULL)
	{
		cur->sort_pos = 0;
		cur = cur->next;
	}
}

void	env_sort(t_main *main)
{
	t_node	*cur;

	sort_reset(main);
	cur = main->head_env;
	while (cur != NULL && cur->sort_pos > 0)
		cur = cur->next;
	if (cur != NULL)
		sort_alphabetical(main);
}
