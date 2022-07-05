/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:52:44 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/05 19:07:14 by lduboulo         ###   ########.fr       */
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
		else
			lst_replace(main, cmd_split[icmd]);
		icmd++;
		g_exit_status = 0;
	}
}

static void	export_wo_arg(t_main *main)
{
	t_node	*cur;
	int		i;

	env_sort(main);
	i = 1;
	while (i <= lst_size(main))
	{
		cur = main->head_env;
		while (cur != NULL && cur->sort_pos != i)
			cur = cur->next;
		if (cur != NULL && cur->value)
			printf("declare -x %s=\"%s\"\n", cur->var, cur->value);
		else if (cur != NULL && !cur->value)
			printf("declare -x %s\n", cur->var);
		i++;
	}
	g_exit_status = 0;
}

void	b_export(t_main *main)
{
	char	**cmd_split;
	char	*input;

	input = cmd_input(main);
	if (ft_strncmp(input, "", 1) == 0)
		export_wo_arg(main);
	else
	{
		cmd_split = ft_split(input, ' ');
		export_variable(main, cmd_split);
	}
	free(input);
}
