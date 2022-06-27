/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:52:44 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/23 18:47:29 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	export_variable(t_main *main, char **cmd_split)
{
	int	icmd;

	icmd = 0;
	while (cmd_split[icmd])
	{
		if (cmd_split[icmd][0] == '=')
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(cmd_split[icmd], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			ft_tab_free((void **)cmd_split);
			g_exit_status = 1;
			break ;
		}
		else if (ft_strchr(cmd_split[icmd], '=') != NULL)
			lst_replace(main, cmd_split[icmd]);
		g_exit_status = 0;
		icmd++;
	}
}

void	b_export(t_main *main)
{
	char	**cmd_split;
	char	*input;

	input = cmd_input(main);
	cmd_split = ft_split(input, ' ');
	export_variable(main, cmd_split);
	free(input);
}
