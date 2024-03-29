/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_duplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:00:56 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/15 13:25:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	dup_input_and_output(t_main *main)
{
	check_for_error_fork(dup2(main->fd.infile, STDIN));
	check_for_error_fork(dup2(main->fd.outfile, STDOUT));
}

void	dup_output(t_main *main, int icmd)
{
	check_for_error_fork(dup2(main->fd.outfile, STDOUT));
	if (icmd > 1)
	{
		check_for_error_fork(dup2(main->fd.io[PIPE_OUT], STDIN));
		close(main->fd.io[PIPE_IN]);
	}
}

void	dup_here_doc(t_main *main, int icmd)
{
	close(main->fd.here_doc[PIPE_IN]);
	check_for_error_fork(dup2(main->fd.here_doc[PIPE_OUT], STDIN));
	if (main->proc.ncmd > 1 && icmd != main->proc.ncmd)
	{
		close(main->fd.new_io[PIPE_OUT]);
		check_for_error_fork(dup2(main->fd.io[PIPE_IN], STDOUT));
	}
}

void	dup_input(t_main *main, int icmd)
{
	check_for_error_fork(dup2(main->fd.infile, STDIN));
	if (main->proc.ncmd > 1 && icmd != main->proc.ncmd)
	{
		check_for_error_fork(dup2(main->fd.io[PIPE_IN], STDOUT));
		close(main->fd.io[PIPE_OUT]);
	}
}

void	only_pipe(t_main *main, int icmd)
{
	if (main->proc.ncmd > 1)
	{
		if (icmd == 1)
		{
			check_for_error_fork(dup2(main->fd.io[PIPE_IN], STDOUT));
			close(main->fd.io[PIPE_OUT]);
		}
		else if (icmd == main->proc.ncmd)
		{
			check_for_error_fork(dup2(main->fd.io[PIPE_OUT], STDIN));
			close(main->fd.io[PIPE_IN]);
		}
		else
		{
			check_for_error_fork(dup2(main->fd.io[PIPE_OUT], STDIN));
			check_for_error_fork(dup2(main->fd.new_io[PIPE_IN], STDOUT));
			close(main->fd.io[PIPE_IN]);
			close(main->fd.new_io[PIPE_OUT]);
		}
	}
}
