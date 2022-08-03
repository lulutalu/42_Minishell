/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:36:03 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/03 21:05:16 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	child_process(t_main *main, int icmd, int ret)
{
	(void)ret;
	if (open_pipe(main, icmd) != 0)
		return (1);
	main->proc.pid = fork();
	if (main->proc.pid == 0)
	{
		who_do_i_dup(main, icmd, ret);
		return (0);
	}
	return (0);
}

void	who_do_i_dup(t_main *main, int icmd, int ret)
{
	if (ret == 0)
		only_pipe(main, icmd);
	else if (ret == RE_INPUT)
		dup_input(main, icmd);
	else if (ret == D_RE_INPUT)
		dup_here_doc(main, icmd);
	else if (ret == RE_OUTPUT || ret == D_RE_OUTPUT)
		dup_output(main, icmd);
	else if (ret == RE_BOTH)
		dup_input_and_output(main);
	else if (ret == RE_BOTH_HERE_DOC)
		dup_here_doc_and_output(main);
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
