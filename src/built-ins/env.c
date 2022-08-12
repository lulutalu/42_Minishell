/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:53:27 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/12 20:14:15 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	env_print_var(t_main *main, t_node *cur, int i)
{
	int	fd;

	fd = STDOUT;
	if (main->proc.ncmd == 1 && main->fd.outfile > 1)
		fd = main->fd.outfile;
	if (i % 2 == 0)
		ft_putstr_fd("\e[38;5;14;5m", fd);
	else
		ft_putstr_fd("\e[38;5;27;5m", fd);
	ft_putstr_fd(cur->var, fd);
	ft_putchar_fd('=', fd);
	ft_putendl_fd(cur->value, fd);
	ft_putstr_fd("\e[0m", fd);
}

int	b_env(t_main *main)
{
	t_node	*cur;
	int		i;

	i = 1;
	cur = main->head_env;
	while (cur != NULL)
	{
		if (cur->value != NULL)
			env_print_var(main, cur, i);
		cur = cur->next;
		i++;
	}
	g_exit_status = 0;
	return (0);
}
