/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:41:45 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/15 12:52:12 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_free(t_main *main)
{
	lst_destroy(main);
	ft_tab_free((void **)main->env);
	to_be_free((void *)&main->input);
	to_be_free((void *)&main->prompt);
	to_be_free((void *)&main->restore_prompt);
	to_be_free((void *)&main->proc.pid);
	if (main->list.head_cell != NULL)
		free_cell_list(main);
	rl_clear_history();
	ft_putstr_fd("exit\n", 1);
}
