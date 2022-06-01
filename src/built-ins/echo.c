/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:20:31 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/01 12:36:00 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

void	b_echo(t_main *main, char **input)
{
	char	*output;

	if (!input[1])
		printf("\n");
	else
	{
		if (ft_strncmp(input[1], "-n", 3) == 0)
		{
			output = ft_substr(main->res, 8, ft_strlen(main->res) - 8);
			printf("%s", output);
		}
		else
		{
			output = ft_substr(main->res, 5, ft_strlen(main->res) - 5);
			printf("%s\n", output);
		}
		free(output);
	}
}
