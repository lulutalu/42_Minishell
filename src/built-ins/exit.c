/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:21:57 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/11 12:31:19 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	too_many_args(void)
{
	printf("exit\n");
	ft_putendl_fd("minishell: exit: too many arguments", 2);
	g_exit_status = 1;
}

static void	free_all(t_main *main)
{
	t_node	*node;

	free(main->prompt);
	free(main->input);
	ft_tab_free((void **)main->input_split);
	clear_history();
	node = main->tail_env;
	while (node->prev != NULL)
	{
		node = node->prev;
		lst_del(main, node->next);
	}
	lst_del(main, node);
	close(main->fd.infile);
	close(main->fd.outfile);
}

static void	not_numeric(t_main *main, char **split)
{
	free_all(main);
	printf("exit\n");
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(split[0], 2);
	ft_tab_free((void **)split);
	ft_putendl_fd(": numeric argument required", 2);
	exit(255);
}

static void	with_arg(t_main *main, char *input)
{
	char	**split;
	int		i;

	split = ft_split(input, ' ');
	i = 0;
	while (split[0][i])
	{
		if (ft_isalpha(split[0][i]) != 0)
		{
			free(input);
			not_numeric(main, split);
		}
		i++;
	}
	if (split[1])
		too_many_args();
	else
	{
		free_all(main);
		free(input);
		g_exit_status = ft_atoi(split[0]);
		ft_tab_free((void **)split);
		printf("exit\n");
		exit(g_exit_status);
	}
}

void	b_exit(t_main *main)
{
	char	*input;

	input = cmd_input(main);
	if (ft_strncmp(input, "", 1) == 0)
	{
		free_all(main);
		free(input);
		printf("exit\n");
		exit(g_exit_status);
	}
	else
		with_arg(main, input);
}
