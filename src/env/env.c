/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:37:05 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/02 15:45:21 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_dup(t_main *main, char **envp)
{
	int		i;
	t_node	*tail;						//only used for easier initialization
//	t_node	*cur;						//uncomment for test

	main->head_env = NULL;
	i = 0;
	while (envp[i]) 					//while envp not NULL to process every line
		lst_add(&main->head_env, &tail, envp[i++]);
/*	cur = main->head_env;
	while (cur != NULL)
	{
		printf("%s=%s\n", cur->var, cur->value);
		cur = cur->next;
	}*/ 								//uncomment for test
}

void	lst_add(t_node **head_env, t_node **tail, char *str)
{
	t_node	*cur; 						//new node
	char	**split;

	cur = ft_calloc(1, sizeof(t_node));	//dynamic allocation of new cell
	ft_mem_alloc_check((void *)cur);	//check correct allocation
	split = ft_split(str, '=');			//separating with '=' to obtain two parts
	cur->var = ft_strdup(split[0]);		//name of the variable ex : PATH
	cur->value = ft_strdup(split[1]);	//value of the variable ex : /Users/lduboulo/.brew/bin
	cur->next = NULL;
	if (*head_env == NULL)				//in case we're at the beginning of the list
	{
		*head_env = cur;
		*tail = cur;
	}
	else								//here, the use of *tail make this operation easy
	{
		(*tail)->next = cur;
		*tail = cur;
	}
	ft_tab_free((void **)split);
}
