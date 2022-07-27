/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:44:20 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/27 18:25:22 by lduboulo         ###   ########.fr       */
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
		if (!main.input)
		{
			ft_putstr_fd(main.restore_prompt, 0);
			main.input_split = ft_split(main.input, ' ');
			b_exit(&main);
		}
		else if (ft_strlen(main.input) >= 0)
		{
			main.input_split = ft_split(main.input, ' ');
			add_history(main.input);
			redirection(&main);
			built_in(&main);
		}
	}
	return (0);
}
