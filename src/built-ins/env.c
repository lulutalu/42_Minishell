/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:53:27 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/23 16:32:49 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*Env command w/o argument only print the actual environnment*/
/*Though env with argument is use to launch a command by specifying*/
/*another environnment in wich to launch the said command*/
void	b_env(t_main *main)
{
	t_node	*cur;

	cur = main->head_env;
	while (cur != NULL)
	{
		if (cur->value != NULL)
			printf("%s=%s\n", cur->var, cur->value);
		cur = cur->next;
	}
	g_exit_status = 0;
}
