/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:32:52 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/11 15:27:38 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handler(int signum)
{
	if (signum == 2)
	{
		ft_putstr_fd("\n", 1);
		exit(1);
	}
}

static void	signals(void)
{
	struct sigaction	doc;

	ft_memset(&doc, 0, sizeof(doc));
	doc.sa_flags = 0;
	doc.sa_handler = handler;
	sigemptyset(&doc.sa_mask);
	signal(SIGQUIT, SIG_IGN);
	sigaction(SIGINT, &doc, NULL);
}

int	here_doc(t_main *main, t_cell *cur)
{
	char				*limiter;
	char				*buf;
	char				*here_doc;

	signals();
	here_doc = ft_calloc(1, sizeof(char));
	limiter = cur->next->data;
	while (1)
	{
		buf = readline("\e[1mHere_doc > \e[0m");
		if (!buf || ft_strncmp(buf, limiter, ft_strlen(limiter)) == 0)
			break ;
		buf = ft_dyn_strjoin(buf, "\n");
		here_doc = ft_dyn_strjoin(here_doc, buf);
		free(buf);
	}
	if (!buf)
	{
		g_exit_status = 0;
		exit(1);
	}
	ft_putstr_fd(here_doc, main->fd.here_doc[PIPE_IN]);
	close(main->fd.here_doc[PIPE_IN]);
	close(main->fd.here_doc[PIPE_OUT]);
	exit(0);
}

int	main_here_doc(t_main *main, t_cell *cur)
{	
	pid_t	pid;
	int		status;

	check_for_error_fork(pipe(main->fd.here_doc));
	pid = fork();
	if (pid < 0)
		exit_error(pid);
	else if (pid == 0)
		here_doc(main, cur);
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		waitpid(pid, &status, 0);
		check_for_signals(main);
		if (WIFEXITED(status) != 0)
			g_exit_status = 1;
		if (WIFSIGNALED(status) == 1)
		{
			close(main->fd.here_doc[PIPE_IN]);
			close(main->fd.here_doc[PIPE_OUT]);
			return (1);
		}
	}
	return (0);
}
