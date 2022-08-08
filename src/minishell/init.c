/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:49:55 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/08 15:04:32 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	struct_init(t_main *main)
{
	main->fd.infile = -1;
	main->fd.outfile = -1;
	main->fd.here_doc[PIPE_IN] = -1;
	main->fd.here_doc[PIPE_OUT] = -1;
	main->fd.io[PIPE_IN] = -1;
	main->fd.io[PIPE_OUT] = -1;
	main->proc.pid = -1;
}
