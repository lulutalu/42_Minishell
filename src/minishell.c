/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo && lzima				            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:33:38 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/02 19:14:54 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status = 0;

int	main(int argc, char **argv, char **envp)
{
	t_main	main;
	int		is_echo = 0;						//WIP
	int		is_cd = 0;							//WIP

	(void)argv;
	if (argc > 1)
	{
		printf(N_ARGS);
		exit(1);
	}
	env_dup(&main, envp);						//function that store env inside linked list
	while (1)
	{
		printf("%d\n", g_exit_status);
		prompt_creation(&main);					//creation of the prompt
		main.input = readline(main.prompt);
		if (ft_strlen(main.input) >= 0)			//even if line is empty, string still alloced
		{										//so strlen is used to check if empty or not
			add_history(main.input);
			if (is_echo == 1)//pseudo-code for now, real variable will be added once parsing is done
				b_echo(&main);					//main.input is temporary here (parsing)
			if (is_cd == 1)
				b_cd(&main);
			free(main.input);
		}
	}
	return (0);
}
