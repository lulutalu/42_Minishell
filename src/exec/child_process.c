/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:36:03 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/08 20:13:25 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	child_process(t_main *main, int icmd)
{
	if (open_pipe(main, icmd) != 0)
		return (1);
	main->proc.pid = fork();
	if (main->proc.pid < 0)
		exit_error(main->proc.pid);
	else if (main->proc.pid == 0)
	{
		who_do_i_dup(main, icmd);
		exec(main, icmd);
	}
	else
		parent_operation(main, icmd);
	return (0);
}

void	parent_operation(t_main *main, int icmd)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(main->proc.pid, &main->proc.status, 0);
	if (WIFSIGNALED(main->proc.status) == 1)
	{
		if (main->proc.status == 3)
			ft_putendl_fd("Quit : 3", 2);
		else
			ft_putendl_fd("", 2);
		g_exit_status = 128 + main->proc.status;
	}
	if (WIFEXITED(main->proc.status) != 0)
		g_exit_status = WEXITSTATUS(main->proc.status);
	if (icmd > 1)
	{
		close(main->fd.io[PIPE_IN]);
		close(main->fd.io[PIPE_OUT]);
		main->fd.io[PIPE_IN] = main->fd.new_io[PIPE_IN];
		main->fd.io[PIPE_OUT] = main->fd.new_io[PIPE_OUT];
	}
}

void	who_do_i_dup(t_main *main, int icmd)
{
	if (main->fd.infile > 0 && main->fd.outfile > 0)
		dup_input_and_output(main);
	else if (main->fd.here_doc[PIPE_IN] > 0 && main->fd.outfile > 0)
		dup_here_doc_and_output(main);
	else if (main->fd.infile > 0)
		dup_input(main, icmd);
	else if (main->fd.here_doc[PIPE_IN] > 0)
		dup_here_doc(main, icmd);
	else if (main->fd.outfile > 0)
		dup_output(main, icmd);
	else
		only_pipe(main, icmd);
}

int	open_pipe(t_main *main, int icmd)
{
	if (main->proc.ncmd > 1)
	{
		if (icmd == 1)
		{
			if (check_for_error(pipe(main->fd.io)) != 0)
				return (1);
		}
		else if (main->proc.npipe > 0)
			if (check_for_error(pipe(main->fd.new_io)) != 0)
				return (1);
		main->proc.npipe--;
	}
	return (0);
}
