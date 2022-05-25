/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:20:31 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/25 11:39:48 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

void	built_ins_echo(t_main *main, char **input)
{
	char	*cmd;
	char	*env;

	if (!input[1])
		printf("\n");
	else if (ft_strncmp(input[1], "-n", 3) == 0)
	{
		cmd = ft_substr(main->input, 8, ft_strlen(main->input) - 8);
		printf("%s", cmd);
	}
	else if (ft_strncmp(input[1], "$", 2) != 0)
	{
		if (ft_strncmp(input[1], "$?", 3) == 0)
			printf("%d\n", g_exit_status);
		else
		{
			env = getenv(ft_substr(input[1], 1, ft_strlen(input[1]) - 1));
			if (env == NULL)
				printf("\n");
			else
				printf("%s\n", env);
		}
	}
	else
	{
		cmd = ft_substr(main->input, 5, ft_strlen(main->input) - 5);
		printf("%s\n", cmd);
	}
	g_exit_status = 0;
}
