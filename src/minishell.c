/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo && lzima				            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:33:38 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/02 14:04:35 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status = 0;

int	main(int argc, char **argv, char **envp)
{
	t_main	main;
	int		is_echo = 0;						//will change in the future (parsing)

	(void)argv;
	if (argc > 1)
	{
		printf(N_ARGS);
		exit(1);
	}
	env_dup(&main, envp);						//function that store env inside linked list
	prompt_creation(&main);						//creation of the prompt
	while (1)
	{
		main.input = readline(main.prompt);
		if (main.input != NULL)
		{
			add_history(main.input);
			if (is_echo == 1)//pseudo-code for now, real variable will be added once parsing is done
				b_echo(&main);					//main.input is temporary here (parsing)
			free(main.input);
		}
	}
	return (0);
}
