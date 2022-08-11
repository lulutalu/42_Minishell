/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:38:55 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/11 21:09:16 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	control_tower(t_main *main)
{
	int	icmd;

	main->proc.pid = ft_calloc(main->proc.ncmd + 1, sizeof(pid_t));
	alloc_check(main->proc.pid);
	main->proc.npipe = main->proc.ncmd - 1;
	icmd = 1;
	while (icmd <= main->proc.ncmd)
	{
		if (launch_process(main, icmd++) != 0)
			break ;
	}
	icmd = 1;
	while (icmd <= main->proc.ncmd)
		wait_process(main, icmd++);
}

void	wait_process(t_main *main, int icmd)
{
	if (main->proc.pid[icmd - 1] != 0)
	{
		waitpid(main->proc.pid[icmd - 1], &main->proc.status, 0);
		g_exit_status = 0;
		if (WIFSIGNALED(main->proc.status) == 1)
		{
			if (main->proc.status == 3)
				ft_putendl_fd("Quit : 3", 2);
			else if (main->proc.status == 2)
				ft_putendl_fd("", 2);
			g_exit_status = 128 + main->proc.status;
		}
		if (WIFEXITED(main->proc.status) != 0)
			g_exit_status = WEXITSTATUS(main->proc.status);
	}
}

int	launch_process(t_main *main, int icmd)
{
	t_cell	*cur;

	cur = main->list.head_cell;
	if (cur != NULL)
	{
		while (cur->pos != icmd && cur != NULL)
			cur = cur->next;
		clear_fd(main);
		if (check_redirection(main, cur, icmd) != 0)
			return (1);
		if (is_built_ins(main, cur, icmd) == 0)
			return (0);
		if (child_process(main, icmd) != 0)
			return (fd_not_valid("pipe"));
	}
	return (0);
}

void	clear_fd(t_main *main)
{
	if (main->fd.infile > 2)
		close(main->fd.infile);
	if (main->fd.outfile > 2)
		close(main->fd.outfile);
	if (main->fd.here_doc[PIPE_IN] > 2)
		close(main->fd.here_doc[PIPE_IN]);
	if (main->fd.here_doc[PIPE_OUT] > 2)
		close(main->fd.here_doc[PIPE_OUT]);
	struct_init(main);
}

int	check_redirection(t_main *main, t_cell *cur, int icmd)
{
	int		ret;

	while (cur->pos == icmd && cur->next != NULL)
	{
		if (cur->token == RE_INPUT)
			ret = redirect_input(main, cur);
		else if (cur->token == D_RE_INPUT)
			ret = main_here_doc(main, cur);
		else if (cur->token == RE_OUTPUT)
			ret = redirect_output(main, cur);
		else if (cur->token == D_RE_OUTPUT)
			ret = redirect_double_output(main, cur);
		if (ret == 1)
			return (1);
		cur = cur->next;
	}
	return (0);
}
