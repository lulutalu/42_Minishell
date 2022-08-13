/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:36:03 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/13 21:09:03 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	child_process(t_main *main, int icmd)
{
	if (open_pipe(main, icmd) != 0)
		return (1);
	main->proc.pid[icmd - 1] = fork();
	if (main->proc.pid[icmd - 1] < 0)
		exit_error(main->proc.pid[icmd - 1]);
	else if (main->proc.pid[icmd - 1] == 0)
	{
		who_do_i_dup(main, icmd);
		if (is_forked_built_ins(main, icmd) == 0)
			exit(g_exit_status);
		exec(main, icmd);
	}
	else
		parent_operation(main, icmd);
	return (0);
}

int	is_forked_built_ins(t_main *main, int icmd)
{
	t_cell	*cur;

	cur = main->list.head_cell;
	if (!cur)
		exit_error(-1);
	cur = avoid_redir(cur, icmd);
	if (strncmp(cur->data, "exit", ft_strlen("exit")) == 0)
	{
		if (b_exit(main, cur, icmd) == 1)
			return (0);
	}
	else if (ft_strcmp_case(cur->data, "cd") == 0)
		return (b_cd(main, cur, icmd));
	else if (ft_strcmp_case(cur->data, "echo") == 0)
		return (b_echo(main, cur, icmd));
	else if (ft_strcmp_case(cur->data, "env") == 0)
		return (b_env(main));
	else if (ft_strncmp(cur->data, "export", ft_strlen("export")) == 0)
		return (b_export(main, cur, icmd));
	else if (ft_strcmp_case(cur->data, "pwd") == 0)
		return (b_pwd(main));
	return (1);
}

void	parent_operation(t_main *main, int icmd)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	close(main->fd.here_doc[PIPE_IN]);
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
	only_pipe(main, icmd);
	if (main->fd.infile > 0 && main->fd.outfile > 0)
		dup_input_and_output(main);
	else if (main->fd.infile > 0)
		dup_input(main, icmd);
	else if (main->fd.outfile > 0)
		dup_output(main, icmd);
	if (main->fd.here_doc[PIPE_IN] > 0 && main->fd.outfile > 0)
		dup_here_doc_and_output(main);
	else if (main->fd.here_doc[PIPE_IN] > 0)
		dup_here_doc(main, icmd);
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
