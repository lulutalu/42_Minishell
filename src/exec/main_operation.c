/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:38:55 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/01 19:41:39 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	control_tower(t_main *main)
{
	int	icmd;

	add_history(main->input);
	main->proc.npipe = main->proc.ncmd - 1;
	icmd = 1;
	while (icmd <= main->proc.ncmd)
		launch_process(main, icmd++);
}

int	launch_process(t_main *main, int icmd)
{
	t_cell	*cur;
	t_cell	*temp;

	cur = main->list.head_cell;
	while ((cur->pos != icmd || cur->token == PIPE) && cur != NULL)
		cur = cur->next;
	temp = cur;
	main->proc.pid = fork();
	if (main->proc.pid == 0)
	{
		if (check_redirection(main, cur, icmd) != 0)
			return (1);
	}
	return (0);
}

int	check_redirection(t_main *main, t_cell *cur, int icmd)
{
	while (cur->pos == icmd && cur->next != NULL)
	{
		if (cur->token == 997 && cur->next->pos == icmd)
		{
			if (redirect_input(main, cur) != 0)
				return (1);
		}
/*		else if (cur->token == 997)
		{
			if (here_doc(main, cur) != 0)
				return (1);
		}*/
		else if (cur->token == 995)
		{
			if (redirect_output(main, cur) != 0)
				return (1);
		}
		else if (cur->token == 994)
		{
			if (redirect_double_output(main, cur) != 0)
				return (1);
		}
		cur = cur->next;
	}
	return (0);
}

/*void	built_in(t_main *main)
{
	if (ft_strcmp_case(main->input_split[0], "echo") == 0)
		b_echo(main);
	else if (ft_strncmp(main->input_split[0], "cd", 3) == 0)
		b_cd(main);
	else if (ft_strcmp_case(main->input_split[0], "pwd") == 0)
		b_pwd();
	else if (ft_strncmp(main->input_split[0], "export", 7) == 0)
		b_export(main);
	else if (ft_strcmp_case(main->input_split[0], "env") == 0)
		b_env(main);
	else if (ft_strncmp(main->input_split[0], "unset", 6) == 0)
		b_unset(main);
	else if (ft_strncmp(main->input_split[0], "exit", 5) == 0)
		b_exit(main);
	free(main->input);
	free(main->prompt);
	ft_tab_free((void **)main->input_split);
}

void	redirection(t_main *main)
{
	if (ft_strchr(main->input, '<') != NULL)
		less_than(main);
	if (ft_strchr(main->input, '>') != NULL)
		more_than(main);
}*/
