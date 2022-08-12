/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:50:53 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/11 18:17:45 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	alloc_check(void *ptr)
{
	if (!ptr)
	{
		g_exit_status = 1;
		ft_putstr_fd("An error as occured during a dynamic allocation\n", 2);
		exit(1);
	}
}

void	exit_error(int value)
{
	if (value < 0)
	{
		perror("");
		g_exit_status = 1;
		exit(g_exit_status);
	}
}

void	check_for_error_fork(int value)
{
	if (value < 0)
	{
		perror("");
		ft_putstr_fd("fd error", 2);
		g_exit_status = 1;
		exit(1);
	}
	g_exit_status = 0;
}

int	check_for_error(int value)
{
	if (value != 0)
	{
		perror("");
		g_exit_status = 1;
		return (g_exit_status);
	}
	g_exit_status = 0;
	return (g_exit_status);
}

int	is_token(t_cell *cur)
{
	if (cur->token != 999 && cur->token != 36 && cur->token != 34
		&& cur->token != 39)
		return (1);
	return (0);
}
