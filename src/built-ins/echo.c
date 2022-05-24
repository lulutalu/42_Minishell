/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:20:31 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/24 16:49:38 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

void	built_ins_echo(t_main *main, char **input)
{
	char	*cmd;

	if (!input[1])
	{
		cmd = ft_substr(main->input, 5, ft_strlen(main->input) - 5);
		printf("%s\n", cmd);
	}
	else if (ft_strncmp(input[1], "-n", 2) == 0)
	{
		cmd = ft_substr(main->input, 8, ft_strlen(main->input) - 8);
		printf("%s", cmd);
	}
	else
	{
		cmd = ft_substr(main->input, 5, ft_strlen(main->input) - 5);
		printf("%s\n", cmd);
	}
}
