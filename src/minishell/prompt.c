/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo && lzima				            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:39:39 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/13 17:22:47 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	restore_prompt(t_main *main, char **split)
{
	char	*len;

	len = ft_itoa(ft_strlen(main->prompt) - 17);
	main->restore_prompt = ft_strdup("\e[A\e[");
	main->restore_prompt = ft_dyn_strjoin(main->restore_prompt, len);
	main->restore_prompt = ft_dyn_strjoin(main->restore_prompt, "C");
	ft_tab_free((void **)split);
	free(len);
}

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
	if (i >= 2)
		main->prompt = ft_dyn_strjoin(main->prompt, split[i - 2]);
	main->prompt = ft_dyn_strjoin(main->prompt, "/");
	if (i >= 1)
		main->prompt = ft_dyn_strjoin(main->prompt, split[i - 1]);
	if (g_exit_status == 0)
		main->prompt = ft_dyn_strjoin(main->prompt, "\e[1;92m");
	else
		main->prompt = ft_dyn_strjoin(main->prompt, "\e[1;91m");
	main->prompt = ft_dyn_strjoin(main->prompt, " ➜ \e[0m");
	restore_prompt(main, split);
}
