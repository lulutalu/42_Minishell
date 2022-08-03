/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_duplication_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:59:49 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/03 21:03:28 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	dup_here_doc_and_output(t_main *main)
{
	check_for_error_fork(dup2(main->fd.outfile, STDOUT));
	check_for_error_fork(dup2(main->fd.here_doc[PIPE_OUT], STDIN));
	close(main->fd.here_doc[PIPE_IN]);
}
