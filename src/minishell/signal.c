/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:23:21 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/08 21:21:18 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ctrl_c(siginfo_t *info)
{
	(void)info;
	ft_putendl_fd("", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
	g_exit_status = 1;
}

static void	ctrl_backslash(void)
{
	rl_on_new_line();
	rl_redisplay();
}

static void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (signum == 2)
		ctrl_c(info);
	else if (signum == 3)
		ctrl_backslash();
}

void	check_for_signals(t_main *main)
{
	ft_memset(&main->sa, 0, sizeof(main->sa));
	main->sa.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	main->sa.sa_sigaction = signal_handler;
	sigemptyset(&main->sa.sa_mask);
	sigaction(SIGQUIT, &main->sa, NULL);
	sigaction(SIGINT, &main->sa, NULL);
}
