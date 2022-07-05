/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:22:08 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/05 19:17:32 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	b_unset(t_main *main)
{
	char	*input;
	char	**split;
	int		i;
	t_node	*cur;

	input = cmd_input(main);
	split = ft_split(input, ' ');
	i = 0;
	while (split[i])
	{
		cur = find_var(main, split[i]);
		if (cur != NULL)
			lst_del(main, cur);
		i++;
	}
	g_exit_status = 0;
	ft_tab_free((void **)split);
	free(input);
}
