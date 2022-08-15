/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:31:10 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/15 13:24:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_built_ins(t_main *main, t_cell *cur, int icmd)
{
	if (icmd == 1 && main->proc.ncmd == 1)
	{
		cur = avoid_redir(cur, icmd);
		if (cur && ft_strncmp(cur->data, "exit", ft_strlen("exit") + 1) == 0)
		{
			if (b_exit(main, cur, icmd) == 1)
				return (0);
		}
		else if (cur && ft_strcmp_case(cur->data, "cd") == 0)
		{
			if (b_cd(main, cur, icmd) == 0)
				return (0);
		}
		else if (cur && ft_strcmp_case(cur->data, "echo") == 0)
			return (b_echo(main, cur, icmd));
		else if (cur && ft_strcmp_case(cur->data, "env") == 0)
			return (b_env(main));
		else if (cur && ft_strncmp(cur->data, "export", 7) == 0)
			return (b_export(main, cur, icmd));
		else if (cur && ft_strcmp_case(cur->data, "pwd") == 0)
			return (b_pwd(main));
		else if (cur && ft_strncmp(cur->data, "unset", 6) == 0)
			return (b_unset(main, cur, icmd));
	}
	return (1);
}
