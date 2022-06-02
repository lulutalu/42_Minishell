/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:20:31 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/02 18:34:14 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

/* Pseudo-code as changes are expected once the parsing is done */
void	b_echo(t_main *main)
{
	int	no_arg = 0;
	int	n_arg = 0;

	if (no_arg == 1)
		printf("\n");
	else if (n_arg == 1)
		printf("%s", main->input);		//use of main->input will change (parsing)
	else
		printf("%s\n", main->input);
	g_exit_status = 0;					//never forget to set correct value for exit code
}
//what about echo ~ ?
