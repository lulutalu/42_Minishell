/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo && lzima				            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2022/06/15 13:45:01 by lduboulo         ###   ########.fr       */
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
	env_dup(&main, envp);						//function that store env inside linked list
	while (1)
	{
		printf("%d\n", g_exit_status);
		prompt_creation(&main);					//creation of the prompt
		main.input = readline(main.prompt);
		if (ft_strlen(main.input) >= 0)			//even if line is empty, string still alloced
		{
			main.input_split = ft_split(main.input, ' ');
			add_history(main.input);
			if (ft_strcmp_case(main.input_split[0], "echo") == 0)
				b_echo(&main);
			else if (ft_strncmp(main.input_split[0], "cd", 3) == 0)
				b_cd(&main);
			else if (ft_strcmp_case(main.input_split[0], "pwd") == 0)
				b_pwd();
			else if (ft_strncmp(main.input_split[0], "export", 7) == 0)
				b_export(&main);
			else if (ft_strcmp_case(main.input_split[0], "env") == 0)
				b_env(&main);
			free(main.input);
			ft_tab_free((void **)main.input_split);
		}
		if (main.input != NULL)
			parser_launcher(main.input);
		if (main.input != NULL)
			parser_launcher(main.input);
	}
	return (0);
}
