/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:26:15 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/27 19:07:03 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	simple_quote(t_main *main)
{
	int		i;
	int		n;
	char	**split;
	char	*tmp;

	n = n_quote(main);
	if (n > 0 && n % 2 == 0)
	{
		split = ft_split(main->input, '\'');
		i = 0;
		while (i < n)
		{
			if (i == 0)
			{
				main->res = ft_strjoin(split[i], split[i + 1]);
				i++;
			}
			else
				main->res = ft_dyn_strjoin(main->res, split[i]);
			i++;
		}
		tmp = ft_substr(main->input, ft_strlen(main->res) + n, \
				ft_strlen(main->input));
		main->res = ft_dyn_strjoin(main->res, tmp);
		memory_flush(&tmp, &split);
	}
}

int	n_quote(t_main *main)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (main->input[i])
	{
		if (main->input[i] == '\'')
			n++;
		i++;
	}
	return (n);
}

void	memory_flush(char **tmp, char ***split)
{
	free(*tmp);
	ft_tab_free((void **)*split);
}
