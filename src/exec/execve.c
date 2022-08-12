/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:20:38 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/12 17:26:22 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec(t_main *main, int icmd)
{
	char	**path;
	char	**args;
	char	*directory;
	int		i;

	path = get_path(main);
	args = get_args(main, icmd);
	i = 0;
	while (path[i])
	{
		if (ft_strchr(args[0], '/') == NULL)
		{
			directory = ft_strjoin(path[i], "/");
			directory = ft_dyn_strjoin(directory, args[0]);
		}
		else
			directory = ft_strdup(args[0]);
		alloc_check(directory);
		if (access(directory, X_OK) == 0)
			execve(directory, args, main->env);
		free(directory);
		i++;
	}
	command_not_found(args[0]);
}

void	command_not_found(char *command)
{
	if (ft_strchr(command, '/') == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command, 2);
		ft_putendl_fd(": command not found", 2);
		g_exit_status = 127;
		exit(g_exit_status);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command, 2);
		ft_putendl_fd(": is a directory", 2);
		g_exit_status = 126;
		exit(g_exit_status);
	}
}

char	**get_args(t_main *main, int icmd)
{
	int		i;
	char	**args;
	t_cell	*cur;

	cur = main->list.head_cell;
	while (cur != NULL && cur->pos != icmd)
		cur = cur->next;
	i = n_args(cur, icmd);
	args = ft_calloc(i + 1, sizeof(char *));
	alloc_check(args);
	i = 0;
	while (cur != NULL && cur->pos == icmd)
	{
		if (cur->token >= 994 && cur->token <= 997)
		{
			cur = cur->next->next;
			continue ;
		}
		args[i] = ft_strdup(cur->data);
		alloc_check(args[i++]);
		cur = cur->next;
	}
	if (args[0] == NULL)
		exit(0);
	return (args);
}

int	n_args(t_cell *cur, int icmd)
{
	int	i;

	i = 0;
	while (cur != NULL && cur->pos == icmd)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

char	**get_path(t_main *main)
{
	t_node	*cur;
	char	**path;

	cur = find_var(main, "PATH");
	if (cur != NULL)
	{
		path = ft_split(cur->value, ':');
		alloc_check((void *)path);
		return (path);
	}
	else
	{
		g_exit_status = 127;
		exit(127);
	}
}
