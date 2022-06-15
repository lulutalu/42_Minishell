/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:53:27 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/09 19:03:53 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*static void	env_arg(t_main *main, char *var)
{
	char	**split;

	split = ft_split(var, ' ');
	if (split[1] != NULL)
		usage_error(
}*/

void	b_env(t_main *main)
{
	t_node	*cur;
	char	*input;

	input = cmd_input(main);
//	if (input != NULL)
//		env_arg(main, input);
	cur = main->head_env;
	while (cur != NULL)
	{
		if (cur->value != NULL)
			printf("%s=%s\n", cur->var, cur->value);
		cur = cur->next;
	}
	g_exit_status = 0;
}
