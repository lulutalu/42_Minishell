/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:49:55 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/14 18:13:36 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	struct_init(t_main *main)
{
	main->fd.infile = -1;
	main->fd.outfile = -1;
	main->fd.here_doc[PIPE_IN] = -1;
	main->fd.here_doc[PIPE_OUT] = -1;
	main->fd.new_io[PIPE_IN] = -1;
	main->fd.new_io[PIPE_OUT] = -1;
	main->input = NULL;
	main->prompt = NULL;
	main->restore_prompt = NULL;
	main->proc.pid = NULL;
	main->list.head_cell = NULL;
	main->list.tail_cell = NULL;
}
