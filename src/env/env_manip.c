/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:41:39 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/05 16:20:59 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*This function is used to find a specific variables in our environnment*/
/*It will return a pointer to the variables if it exists*/
/*ex : char *var = "HOME" --> t_node *cur = "HOME" variable position in linked
	list*/
t_node	*find_var(t_main *main, char *var)
{
	t_node	*cur;

	cur = main->head_env;
	while (cur != NULL && ft_strncmp(cur->var, var, ft_strlen(var) + 1) != 0)
		cur = cur->next;
	return (cur);
}

/*This function is used to add a node inside the linked list*/
/*It will always add the new node at the end of the linked list*/
/*To add correctly a new variable, char *str must be formatted correctly*/
/*char *str = "NAME_VAR=VALUE_VAR"*/
/*ex : "HOME=/Users/lduboulo"*/
void	lst_add(t_node **head_env, t_node **tail, char *str)
{
	t_node	*cur;
	char	**split;

	cur = ft_calloc(1, sizeof(t_node));
	ft_mem_alloc_check((void *)cur);
	split = ft_split(str, '=');
	cur->var = ft_strdup(split[0]);
	cur->value = ft_strdup(split[1]);
	cur->next = NULL;
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
	ft_tab_free((void **)split);
}

/*This function is used to delete a certain node and correctly free it*/
/*The node that will be deleted will be the one pointed by *cur*/
void	lst_del(t_main *main, t_node *cur)
{
	if (cur->prev != NULL)
		cur->prev->next = cur->next;
	else
	{
		main->head_env = cur->next;
		main->head_env->prev = NULL;
	}
	if (cur->next != NULL)
		cur->next->prev = cur->prev;
	else
		cur->prev->next = NULL;
	free(cur->var);
	free(cur->value);
	free(cur);
}

/*This function will replace the value of an existing env variables*/
/*char *var must be equal to the complete variable *see example*/
/*ex : char *var = "PWD=/Users/lduboulo/Downloads"*/
/*in case the variables doesn't exist, it will add it by calling lst_add*/
/*be aware that char *var is malloc'ed*/
void	lst_replace(t_main *main, char *var)
{
	t_node	*cur;
	char	**split;

	split = ft_split(var, '=');
	cur = find_var(main, split[0]);
	if (cur == NULL)
		lst_add(&main->head_env, &main->tail_env, var);
	else
	{
		free(cur->value);
		cur->value = ft_strdup(split[1]);
	}
	ft_tab_free((void **)split);
	free(var);
}
