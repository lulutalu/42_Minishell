/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:22:08 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/13 21:27:48 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	unset_error(t_cell *cur)
{
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd(cur->data, 2);
	ft_putendl_fd("': not a valid identifier", 2);
	return (1);
}

static int	unset_var(t_main *main, t_cell *cur)
{
	int		i;
	t_node	*n_cur;

	if (ft_isdigit(cur->data[0]) == 1)
		return (unset_error(cur));
	i = -1;
	while (cur->data[++i])
		if (ft_isalnum(cur->data[i]) == -1 && cur->data[i] != '_')
			return (unset_error(cur));
	n_cur = find_var(main, cur->data);
	if (n_cur)
		lst_del(main, n_cur);
	return (0);
}

int	b_unset(t_main *main, t_cell *cur, int icmd)
{
	if (cur->next != NULL)
		cur = avoid_redir(cur, icmd);
	else if (cur->next == NULL)
		return (g_exit_status = 0);
	while (cur != NULL && cur->pos == icmd)
	{
		if (cur->token >= 994 && cur->token <= 997)
		{
			cur = cur->next->next;
			continue ;
		}
		g_exit_status = unset_var(main, cur);
		cur = cur->next;
	}
	return (0);
}
