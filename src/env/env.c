/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:37:05 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/05 16:26:17 by lduboulo         ###   ########.fr       */
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
