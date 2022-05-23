/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo && lzima				            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:39:39 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/23 20:15:33 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	prompt_creation(t_main *main)
{
	char	*user;
	char	pwd[4096];
	char	**split;
	int		i;

	user = getenv("USER");
	getcwd(pwd, 4096);
	split = ft_split(pwd, '/');
	i = 0;
	while (split[i])
		i++;
	main->prompt = ft_strdup("\e[1m");
	main->prompt = ft_dyn_strjoin(main->prompt, user);
	main->prompt = ft_dyn_strjoin(main->prompt, " % ");
	main->prompt = ft_dyn_strjoin(main->prompt, split[i - 2]);
	main->prompt = ft_dyn_strjoin(main->prompt, "/");
	main->prompt = ft_dyn_strjoin(main->prompt, split[i - 1]);
	main->prompt = ft_dyn_strjoin(main->prompt, "\e[1;92m");
	main->prompt = ft_dyn_strjoin(main->prompt, " ➜ \e[0m");
}
