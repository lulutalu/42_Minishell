/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:44:20 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/01 19:44:38 by lduboulo         ###   ########.fr       */
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
	main.fd.infile = -1;
	main.fd.outfile = -1;
	check_for_signals(&main);
	while (1)
	{
		prompt_creation(&main);
		main.input = readline(main.prompt);
		if (parser_main_quote(main.input, &main) == 1)
			ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
/*		else
		{
			if (!main.input)
			{
				ft_putstr_fd(main.restore_prompt, 0);
				b_exit(&main);
			}
			else
				control_tower(&main);
		}*/
	}
	return (0);
}
