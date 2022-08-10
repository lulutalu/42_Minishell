/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:38:55 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/09 20:34:09 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	control_tower(t_main *main)
{
	int	icmd;

	main->proc.npipe = main->proc.ncmd - 1;
	icmd = 1;
	while (icmd <= main->proc.ncmd)
		if (launch_process(main, icmd++) != 0)
			break ;
}

int	launch_process(t_main *main, int icmd)
{
	t_cell	*cur;

	cur = main->list.head_cell;
	if (cur != NULL)
	{
		while ((cur->pos != icmd || cur->token == PIPE) && cur != NULL)
			cur = cur->next;
		clear_fd(main);
		if (check_redirection(main, cur, icmd) != 0)
			return (1);
		if (child_process(main, icmd) != 0)
			return (fd_not_valid("pipe"));
	}
	return (0);
}

void	clear_fd(t_main *main)
{
	close(main->fd.infile);
	close(main->fd.outfile);
	close(main->fd.here_doc[PIPE_IN]);
	close(main->fd.here_doc[PIPE_OUT]);
	main->fd.infile = -1;
	main->fd.outfile = -1;
	main->fd.here_doc[PIPE_IN] = -1;
	main->fd.here_doc[PIPE_OUT] = -1;
	main->proc.pid = -1;
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
