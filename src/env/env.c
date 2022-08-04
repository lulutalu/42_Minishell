/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:37:05 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/04 15:18:46 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*Function to duplicate the **envp variable at the beginning of the programm*/
/*That way, the environnment can be modified during the programm*/
/*This function might be moved in the future*/
void	env_dup(t_main *main, char **envp)
{
	int		i;

	main->head_env = NULL;
	main->tail_env = NULL;
	i = 0;
	while (envp[i])
		lst_add(&main->head_env, &main->tail_env, envp[i++]);
	main->env = NULL;
	tab_format_env(main);
}

void	tab_format_env(t_main *main)
{
	int		i;
	char	*str;
	t_node	*cur;

	if (main->env)
		ft_tab_free((void **)main->env);
	i = lst_size(main);
	main->env = ft_calloc(i + 1, sizeof(char *));
	alloc_check(main->env);
	cur = main->head_env;
	i = 0;
	while (cur != NULL)
	{
		str = ft_strjoin(cur->var, "=");
		str = ft_dyn_strjoin(str, cur->value);
		main->env[i] = ft_strdup(str);
		alloc_check(main->env[i++]);
		free(str);
		cur = cur->next;
	}
}

static void	value_assignation(t_node *cur, char *str)
{
	char	**split;
	char	*chr;

	split = ft_split(str, '=');
	cur->var = ft_strdup(split[0]);
	chr = ft_strchr(str, '=');
	if (chr)
		cur->value = ft_strdup(chr + 1);
	else
		cur->value = NULL;
	cur->sort_pos = 0;
	cur->next = NULL;
	ft_tab_free((void **)split);
}

/*This function is used to add a node inside the linked list*/
/*It will always add the new node at the end of the linked list*/
/*To add correctly a new variable, char *str must be formatted correctly*/
/*char *str = "NAME_VAR=VALUE_VAR"*/
/*ex : "HOME=/Users/lduboulo"*/
void	lst_add(t_node **head_env, t_node **tail, char *str)
{
	t_node	*cur;

	cur = ft_calloc(1, sizeof(t_node));
	ft_mem_alloc_check((void *)cur);
	value_assignation(cur, str);
	if (*head_env == NULL)
	{
		cur->prev = NULL;
		*head_env = cur;
		*tail = cur;
	}
	else
	{
		cur->prev = *tail;
		(*tail)->next = cur;
		*tail = cur;
	}
}
