/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:20:31 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/05 11:41:56 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

/* Pseudo-code as changes are expected once the parsing is done */
/*With the parsing done, there might be some adjustment in here*/
/*Might need to check for commands like "echo ~"*/
/*As of right now, the idea is to receive some simple boolean*/
/*that tell wich operation should be done based on the parsing*/
void	b_echo(t_main *main)
{
	int		no_arg;
	int		n_arg;
	char	*input;

	input = cmd_input(main);
	no_arg = 0;
	n_arg = 0;
	if (no_arg == 1)
		printf("\n");
	else if (n_arg == 1)
		printf("%s", input);
	else
		printf("%s\n", input);
	free(input);
	g_exit_status = 0;
}
//what about echo ~ ?
