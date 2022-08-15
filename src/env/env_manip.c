/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:41:39 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/15 13:30:07 by marvin           ###   ########.fr       */
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

/*This function is used to delete a certain node and correctly free it*/
/*The node that will be deleted will be the one pointed by *cur*/
void	lst_del(t_main *main, t_node *cur)
{
	if (cur == main->tail_env && cur->prev != NULL)
	{
		main->tail_env = cur->prev;
		main->tail_env->next = NULL;
	}
	else if (cur == main->head_env && cur->next != NULL)
	{
		main->head_env = cur->next;
		main->head_env->prev = NULL;
	}
	else if (cur->prev != NULL && cur->next != NULL)
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	}
	else if (cur == main->tail_env && cur == main->head_env)
	{
		main->head_env = NULL;
		main->tail_env = NULL;
	}
	free(cur->var);
	free(cur->value);
	free(cur);
	tab_format_env(main);
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
		if (ft_strchr(var, '=') != NULL)
		{
			free(cur->value);
			cur->value = ft_strdup(ft_strchr(var, '=') + 1);
		}
	}
	tab_format_env(main);
	ft_tab_free((void **)split);
}

int	lst_size(t_main *main)
{
	t_node	*cur;
	int		i;

	i = 0;
	cur = main->head_env;
	while (cur != NULL)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}
