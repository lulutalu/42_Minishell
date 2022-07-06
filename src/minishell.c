/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:44:20 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/06 18:48:12 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/minishell.h"

int	g_exit_status = 0;

int	main(int argc, char **argv, char **envp)
{
	t_main	main;

	(void)argv;
	if (argc > 1)
	{
		printf(N_ARGS);
		exit(1);
	}
	env_dup(&main, envp);
	while (1)
	{
		prompt_creation(&main);
		main.input = readline(main.prompt);
		if (ft_strlen(main.input) >= 0)
		{
			main.input_split = ft_split(main.input, ' ');
			add_history(main.input);
			built_in(&main);
		}
	}
	return (0);
}
