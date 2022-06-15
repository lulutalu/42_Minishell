/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:52:44 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/09 18:44:23 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*static void export_no_arg(t_main *main)
{
	t_node	*cur;

	cur = main->head_env;
	while (cur != NULL)
	{
		printf("");
	}
}*/

static void	export_variable(t_main *main, char **cmd_split)
{
	int	icmd;

	icmd = 0;
	while (cmd_split[icmd])
	{
		if (cmd_split[icmd][0] == '=')
		{
			ft_putstr_fd("minishell: export: '", 2);
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

	input = ft_strchr(main->input, ' ');
	if (input != NULL)
		input = ft_strdup(input + 1);
	else
		input = ft_strdup("");
	cmd_split = ft_split(input, ' ');
	export_variable(main, cmd_split);
}
