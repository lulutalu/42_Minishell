/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:50:53 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/02 18:56:18 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
