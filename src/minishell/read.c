/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:22:44 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/13 22:36:56 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	main_operation(t_main *main)
{
	check_for_signals(main);
	if (main->prompt)
	{
		free(main->prompt);
		main->prompt = NULL;
	}
	prompt_creation(main);
	main->input = readline(main->prompt);
	add_history(main->input);
	if (!main->input)
	{
		ft_putstr_fd(main->restore_prompt, 0);
		b_exit(main, NULL, 0);
	}
	else if (parser_main_quote(main->input, main) == 1)
	{
		g_exit_status = 258;
		ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
	}
	else if (main->list.head_cell != NULL)
		control_tower(main);
}
