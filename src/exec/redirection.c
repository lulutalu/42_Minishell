/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:40:01 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/04 19:49:21 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	fd_not_valid(char *filename)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	g_exit_status = 1;
	return (g_exit_status);
}

int	redirect_input(t_main *main, t_cell *cur)
{
	main->fd.infile = open(cur->next->data, O_RDONLY);
	if (main->fd.infile < 0)
		return (fd_not_valid(cur->next->data));
	g_exit_status = 0;
	return (g_exit_status);
}

int	redirect_output(t_main *main, t_cell *cur)
{
	main->fd.outfile = open(cur->next->data, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (main->fd.outfile < 0)
		return (fd_not_valid(cur->next->data));
	g_exit_status = 0;
	return (g_exit_status);
}

int	redirect_double_output(t_main *main, t_cell *cur)
{
	main->fd.outfile = open(cur->next->data, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (main->fd.outfile < 0)
		return (fd_not_valid(cur->next->data));
	g_exit_status = 0;
	return (g_exit_status);
}

int	here_doc(t_main *main, t_cell *cur)
{
	char	*limiter;
	char	*buf;
	char	*here_doc;

	here_doc = ft_calloc(1, sizeof(char));
	limiter = ft_strjoin(cur->next->data, "\n");
	while (1)
	{
		ft_putstr_fd("\e[1mhere_doc > \e[0m", 1);
		buf = get_next_line(0);
		if (!buf || ft_strncmp(buf, limiter, ft_strlen(buf)) == 0)
			break ;
		here_doc = ft_dyn_strjoin(here_doc, buf);
		free(buf);
	}
	check_for_error_fork(pipe(main->fd.here_doc));
	ft_putstr_fd(here_doc, main->fd.here_doc[PIPE_IN]);
	free(here_doc);
	free(buf);
	return (g_exit_status);
}
