/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:44:20 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/08 15:48:33 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status = 0;

int	main(int argc, char **argv, char **envp)
{
	t_main	main;

	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd(N_ARGS, 2);
		exit(1);
	}
	env_dup(&main, envp);
	struct_init(&main);
	while (1)
	{
		check_for_signals(&main);
		prompt_creation(&main);
		main.input = readline(main.prompt);
		add_history(main.input);
		if (!main.input)
		{
			ft_putstr_fd(main.restore_prompt, 0);
			b_exit(&main);
		}
		else if (parser_main_quote(main.input, &main) == 1)
		{
			g_exit_status = 258;
			ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
		}
		else
			control_tower(&main);
	}
	return (0);
}
