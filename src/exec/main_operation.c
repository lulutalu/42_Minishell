/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:38:55 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/08 18:27:17 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	built_in(t_main *main)
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
}
