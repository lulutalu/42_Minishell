/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo && lzima				            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:33:38 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/01 15:21:09 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status = 0;

int	main(int argc, char **argv, char **envp)
{
	t_main	main;
	char	**split;

	(void)argv;
	if (argc > 1)
	{
		printf(N_ARGS);
		exit(1);
	}
	env_dup(&main, envp);
	prompt_creation(&main);
	while (1)
	{
		main.input = readline(main.prompt);
		if (main.input != NULL)
		{
			simple_quote(&main);
			add_history(main.input);
			split = ft_split(main.input, ' ');
			if (ft_strcmp_case(split[0], "echo") == 0)
				b_echo(&main, split);
			ft_tab_free((void **)split);
			free(main.input);
		}
	}
	return (0);
}
