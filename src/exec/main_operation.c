/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:38:55 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/03 20:57:16 by lduboulo         ###   ########.fr       */
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
	int		redirect;
	int		d_redirect;
	int		ret;

	redirect = 0;
	d_redirect = 0;
	cur = main->list.head_cell;
	if (cur != NULL)
	{
		while ((cur->pos != icmd || cur->token == PIPE) && cur != NULL)
			cur = cur->next;
		redirect = check_redirection(main, cur, icmd);
		if (redirect == 1)
			return (1);
		if (cur->next != NULL)
			d_redirect = check_redirection(main, cur->next, icmd);
		if (d_redirect == 1)
			return (1);
		ret = check_redirection_combo(redirect, d_redirect);
		printf("%d\n", ret);
		if (child_process(main, icmd, ret) != 0)
			return (fd_not_valid("pipe"));
	}
	return (0);
}

int	check_redirection_combo(int re1, int re2)
{
	if (re1 != re2 && re1 != 0)
	{
		if (re1 == D_RE_INPUT || re2 == D_RE_INPUT)
			return (RE_BOTH_HERE_DOC);
		else
			return (RE_BOTH);
	}
	return (re1);
}

int	check_redirection(t_main *main, t_cell *cur, int icmd)
{
	int	ret;

	ret = 0;
	while (cur->pos == icmd && cur->next != NULL && ret == 0)
	{
		if (cur->token == RE_INPUT)
			ret = redirect_input(main, cur);
		else if (cur->token == D_RE_INPUT)
			ret = here_doc(main, cur);
		else if (cur->token == RE_OUTPUT)
			ret = redirect_output(main, cur);
		else if (cur->token == D_RE_OUTPUT)
			ret = redirect_double_output(main, cur);
		if (ret == 1)
			return (1);
		cur = cur->next;
	}
	return (ret);
}
