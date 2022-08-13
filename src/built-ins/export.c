/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:52:44 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/13 21:04:46 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	export_variable(t_main *main, t_cell *cur)
{
	int	status;

	status = -1;
	if (export_is_syntax_ok(cur->data) == TRUE)
		lst_replace(main, cur->data);
	else
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(cur->data, 2);
		ft_putendl_fd("': not a valid identifier", 2);
		status = 0;
	}
	return (status + 1);
}

static void	export_print_value(t_node *cur, int fd, int i)
{
	if (i % 2 == 1)
		ft_putstr_fd("\e[38;5;14m", fd);
	else
		ft_putstr_fd("\e[35;5;34m", fd);
	ft_putstr_fd("declare -x ", fd);
	ft_putstr_fd(cur->var, fd);
	ft_putstr_fd("=\"", fd);
	ft_putstr_fd(cur->value, fd);
	ft_putendl_fd("\"\e[0m", fd);
}

static void	export_print_no_value(t_node *cur, int fd, int i)
{
	if (i % 2 == 1)
		ft_putstr_fd("\e[38;5;14m", fd);
	else
		ft_putstr_fd("\e[35;5;34m", fd);
	ft_putstr_fd("declare -x ", fd);
	ft_putstr_fd(cur->var, fd);
	ft_putendl_fd("\e[0m", fd);
}

static void	export_wo_arg(t_main *main)
{
	t_node	*cur;
	int		i;
	int		fd;

	fd = STDOUT;
	if (main->proc.ncmd == 1 && main->fd.outfile > 1)
		fd = main->fd.outfile;
	env_sort(main);
	i = 1;
	while (i <= lst_size(main))
	{
		cur = main->head_env;
		while (cur != NULL && cur->sort_pos != i)
			cur = cur->next;
		if (cur != NULL && cur->value)
			export_print_value(cur, fd, i);
		else if (cur != NULL && !cur->value)
			export_print_no_value(cur, fd, i);
		i++;
	}
	g_exit_status = 0;
}

int	b_export(t_main *main, t_cell *cur, int icmd)
{
	if (cur->next != NULL)
		cur = avoid_redir(cur->next, icmd);
	else if (cur->next == NULL)
	{
		export_wo_arg(main);
		return (0);
	}
	if (cur == NULL)
		export_wo_arg(main);
	else
	{
		while (cur != NULL && cur->pos == icmd)
		{
			if (cur->token >= 994 && cur->token <= 997)
			{
				cur = cur->next->next;
				continue ;
			}
			g_exit_status = export_variable(main, cur);
			cur = cur->next;
		}
	}
	return (0);
}
