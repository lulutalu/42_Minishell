/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:44:20 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/31 18:31:05 by lduboulo         ###   ########.fr       */
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
		parser_main_quote(main.input, &main);
		print_list(main.list);
		if (!main.input)
		{
			ft_putstr_fd(main.restore_prompt, 0);
			b_exit(&main);
		}
		else
			control_tower(&main);
	}
	return (0);
}
