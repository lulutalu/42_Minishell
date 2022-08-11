/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:31:10 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/11 20:39:39 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_built_ins(t_main *main, t_cell *cur, int icmd)
{
	cur = avoid_redir(cur, icmd);
	if (ft_strncmp(cur->data, "exit", ft_strlen(cur->data)) == 0)
	{
		if (icmd == 1 && main->proc.ncmd == 1)
			if (b_exit(main, cur, icmd) == 1)
				return (0);
	}
	return (1);
}
