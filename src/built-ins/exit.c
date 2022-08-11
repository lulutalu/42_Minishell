/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:21:57 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/11 20:22:18 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	not_numeric(t_main *main, t_cell *cur)
{
	int		i;

	i = 0;
	while (cur->data[i])
	{
		if (ft_isdigit(cur->data[i++]) != 1)
		{
			exit_free(main);
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(cur->data, 2);
			ft_putendl_fd(": numeric argument required", 2);
			exit(255);
		}
	}
}

static int	too_many_args(t_cell *cur, int icmd)
{
	int	n;

	n = 0;
	while (cur != NULL && cur->pos == icmd)
	{
		if (cur->token == 999 || cur->token == DOLLAR || cur->token == S_QUOTE \
				|| cur->token == D_QUOTE)
			n++;
		cur = cur->next;
	}
	if (n > 1)
	{
		ft_putendl_fd("exit", 1);
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		g_exit_status = 1;
		return (1);
	}
	else
		return (0);
}

static void	correct_arg(t_main *main, t_cell *cur, int icmd)
{
	int	exit_value;

	exit_value = ft_atoi(cur->data);
	if (exit_value < 0 || exit_value > 255)
		exit_value %= 256;
	if (icmd == 1 && main->proc.ncmd == 1)
		exit_free(main);
	exit(exit_value);
}

static void	normal_exit(t_main *main, int icmd)
{
	if (icmd == 1 && main->proc.ncmd == 1)
		exit_free(main);
	exit(g_exit_status);
}

int	b_exit(t_main *main, t_cell *cur, int icmd)
{
	t_cell	*tmp;

	tmp = cur;
	if (cur == NULL || cur->next == NULL || cur->next->pos != icmd)
		normal_exit(main, icmd);
	else
	{
		cur = avoid_redir(cur->next, icmd);
		if (cur == NULL)
			normal_exit(main, icmd);
	}
	not_numeric(main, cur);
	if (too_many_args(cur, icmd) == 1)
		return (1);
	correct_arg(main, cur, icmd);
	return (0);
}
