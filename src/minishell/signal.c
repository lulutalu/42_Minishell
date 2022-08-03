/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:23:21 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/03 19:41:32 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ctrl_c(void)
{
	g_exit_status = 1;
	ft_putendl_fd("", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

static void	ctrl_backslash(void)
{
	rl_on_new_line();
	rl_redisplay();
}

static void	signal_handler(int signum)
{
	if (signum == 2)
		ctrl_c();
	else if (signum == 3)
		ctrl_backslash();
}

void	check_for_signals(t_main *main)
{
	main->sa.sa_handler = signal_handler;
	main->sa.sa_flags = 0;
	sigemptyset(&main->sa.sa_mask);
	sigaction(SIGQUIT, &main->sa, NULL);
	sigaction(SIGINT, &main->sa, NULL);
}
