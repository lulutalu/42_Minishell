/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:12:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/27 15:06:54 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*cmd_input(t_main *main)
{
	char	*input;

	if (main->input)
	{
		input = ft_strchr(main->input, ' ');
		input = ft_strdup(input + 1);
	}
	else
		input = ft_strdup("");
	return (input);
}
