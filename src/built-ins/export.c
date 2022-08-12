/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:52:44 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/12 23:11:15 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	export_variable(t_main *main, char **cmd_split)
{
	int	icmd;

	icmd = 0;
	while (cmd_split[icmd])
	{
		if (cmd_split[icmd][0] == '=')
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(cmd_split[icmd], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			g_exit_status = 1;
			break ;
		}
		else
			lst_replace(main, cmd_split[icmd]);
		icmd++;
		g_exit_status = 0;
	}
	ft_tab_free((void **)cmd_split);
}

static void	export_print_value(t_node *cur, int fd, int i)
{
	if (i % 2 == 1)
		ft_putstr_fd("\e[38;5;14m", fd);
	else
		ft_putstr_fd("\e[35;5;27m", fd);
	ft_putstr_fd("declare -x ", fd);
	ft_putstr_fd(cur->var, fd);
	ft_putstr_fd("=\"", fd);
	ft_putstr_fd(cur->value, fd);
	ft_putendl_fd("\"\e[0m", fd);
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
			printf("declare -x %s\n", cur->var);
		i++;
	}
	g_exit_status = 0;
}

int	b_export(t_main *main, t_cell *cur, int icmd)
{
	cur = avoid_redir(cur->next, icmd);
	if (cur == NULL)
		export_wo_arg(main);
	else
	{
		export_variable(main, &cur->data);
	}
	return (0);
}
