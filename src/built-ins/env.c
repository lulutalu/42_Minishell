/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:53:27 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/28 15:50:23 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*Env command w/o argument only print the actual environnment*/
/*Though env with argument is use to launch a command by specifying*/
/*another environnment in wich to launch the said command*/
void	b_env(t_main *main)
{
	t_node	*cur;

	env_sort(main);
	cur = main->head_env;
	while (cur != NULL)
	{
		if (cur->value != NULL)
			printf("%s=%s sort : %d\n", cur->var, cur->value, cur->sort_pos);
		cur = cur->next;
	}
	g_exit_status = 0;
}
