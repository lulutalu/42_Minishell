/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:37:05 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/04 17:21:13 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_dup(t_main *main, char **envp)
{
	int		i;
//	t_node	*cur;						//uncomment for test

	main->head_env = NULL;
	main->tail_env = NULL;
	i = 0;
	while (envp[i]) 					//while envp not NULL to process every line
		lst_add(&main->head_env, &main->tail_env, envp[i++]);
/*	cur = main->head_env;
	while (cur != NULL)
	{
		printf("%s=%s\n", cur->var, cur->value);
		cur = cur->next;
	}*/ 								//uncomment for test
}












































