/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:37:05 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/28 18:23:00 by lduboulo         ###   ########.fr       */
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
}

void	env_sort(t_main *main)
{
	t_node	*cur;

	cur = main->head_env;
	while (cur != NULL && cur->sort_pos)
		cur = cur->next;
	if (cur != NULL)
		sort_alphabetical(main);
}

void	sort_alphabetical(t_main *main)
{
	t_node	*cur;
	t_node	*temp;

	cur = main->head_env->next;
	temp = main->head_env;
	while (cur != NULL)
	{
		if (ft_strncmp(temp->var, cur->var, ft_strlen(temp->var)) > 0)
			temp = cur;
		cur = cur->next;
	}
	temp->sort_pos = 1;
	sort_all_alphabetical(main, temp);
}

void	sort_all_alphabetical(t_main *main, t_node *lowest)
{
	t_node	*cur;
	t_node	*temp;
	int		i;

	i = 2;
	while (i <= lst_size(main))
	{
		temp = main->head_env;
		cur = temp->next;
		while (cur != NULL)
		{
			printf("First %d\nSecond %d\n", ft_strncmp(temp->var, cur->var, ft_strlen(temp->var)), ft_strncmp(cur->var, lowest->var, ft_strlen(cur->var)));
			if (ft_strncmp(temp->var, cur->var, ft_strlen(temp->var)) > 0 && \
				ft_strncmp(cur->var, lowest->var, ft_strlen(cur->var)) < 0)
				temp = cur;
			cur = cur->next;
		}
		temp->sort_pos = i++;
		lowest = temp;
	}
}
