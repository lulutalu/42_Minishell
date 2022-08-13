/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:41:45 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/13 22:23:48 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_free(t_main *main)
{
	lst_destroy(main);
	ft_tab_free((void **)main->env);
	ft_putstr_fd("exit\n", 1);
}
