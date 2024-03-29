/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_duplication_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:59:49 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/15 13:30:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	dup_here_doc_and_output(t_main *main)
{
	check_for_error_fork(dup2(main->fd.outfile, STDOUT));
	check_for_error_fork(dup2(main->fd.here_doc[PIPE_OUT], STDIN));
	ft_putnbr_fd(main->fd.here_doc[PIPE_IN], 2);
	close(main->fd.here_doc[PIPE_IN]);
}
