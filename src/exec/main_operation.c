/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:38:55 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/02 19:48:21 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	control_tower(t_main *main)
{
	int	icmd;

	main->proc.npipe = main->proc.ncmd - 1;
	icmd = 1;
	while (icmd <= main->proc.ncmd)
		if (launch_process(main, icmd++) != 0)
			break ;
}

int	launch_process(t_main *main, int icmd)
{
	t_cell	*cur;
	t_cell	*temp;
	int		ret;

	ret = 0;
	cur = main->list.head_cell;
	if (cur != NULL)
	{
		while ((cur->pos != icmd || cur->token == PIPE) && cur != NULL)
			cur = cur->next;
		temp = cur;
		ret = check_redirection(main, cur, icmd);
		if (ret == 1)
			return (1);
		child_process(t_main *main, int icmd, int ret);
	}
	return (0);
}

int	check_redirection(t_main *main, t_cell *cur, int icmd)
{
	while (cur->pos == icmd && cur->next != NULL)
	{
		if (cur->token == RE_INPUT)
		{
			if (redirect_input(main, cur) != RE_INPUT)
				return (1);
		}
		else if (cur->token == D_RE_INPUT)
		{
			if (here_doc(main, cur) != D_RE_INPUT)
				return (1);
		}
		else if (cur->token == RE_OUTPUT)
		{
			if (redirect_output(main, cur) != RE_OUTPUT)
				return (1);
		}
		else if (cur->token == D_RE_OUTPUT)
		{
			if (redirect_double_output(main, cur) != D_RE_OUTPUT)
				return (1);
		}
		cur = cur->next;
	}
	return (0);
}
