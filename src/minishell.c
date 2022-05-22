/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:33:38 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/21 21:43:49 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	t_main	main;
	(void)argv;

	if (argc > 1)
	{
		printf(N_ARGS);
		exit(1);
	}
	prompt_creation(&main);
	while (1)
		readline(main.prompt);
	return (0);
}
