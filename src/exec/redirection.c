/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:40:01 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/08 18:27:14 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_for_arg(char *input, char sep)
{
	input = (ft_strchr(input, sep) + 1);
	if (input[0] == '\0')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token", 2);
		return (0);
	}
	else
		return (1);
}

void	less_than(t_main *main)
{
	char	*filepath;
	char	**split;
	int		isplit;

	if (check_for_arg(main->input, '<'))
	{
		split = ft_split(ft_strchr(main->input, '<') + 1, ' ');
		isplit = 0;
		while (split[isplit])
			isplit++;
		filepath = ft_strdup(split[isplit - 1]);
		ft_tab_free((void **)split);
		main->fd.infile = open(filepath, O_RDONLY);
		if (main->fd.infile < 0)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(filepath, 2);
			ft_putstr_fd(": ", 2);
			perror("");
		}
		printf("%d\n", main->fd.infile);
	}
}
