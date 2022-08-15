/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo && lzima				            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:39:39 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/15 14:30:37 by lduboulo         ###   ########.fr       */
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

static char	*find_user_if_unset(t_main *main)
{
	t_node	*cur;

	cur = find_var(main, "USER");
	if (cur != NULL)
		return (cur->value);
	else
		return (NULL);
}

static void	too_long(t_main *main)
{
	if (g_exit_status == 0)
		main->prompt = ft_dyn_strjoin(main->prompt, "\e[1;92m");
	else
		main->prompt = ft_dyn_strjoin(main->prompt, "\e[1;91m");
	main->prompt = ft_dyn_strjoin(main->prompt, " ➜ \e[0m");
}

void	prompt_creation(t_main *main)
{
	char	*user;
	char	pwd[4096];
	char	**split;
	int		i;

	user = getenv("USER");
	if (user == NULL)
		user = find_user_if_unset(main);
	getcwd(pwd, 4096);
	split = ft_split(pwd, '/');
	i = 0;
	while (split[i])
		i++;
	main->prompt = ft_strdup("\e[0m\e[1m");
	if (user != NULL)
		main->prompt = ft_dyn_strjoin(main->prompt, user);
	main->prompt = ft_dyn_strjoin(main->prompt, " % ");
	if (i >= 2)
		main->prompt = ft_dyn_strjoin(main->prompt, split[i - 2]);
	main->prompt = ft_dyn_strjoin(main->prompt, "/");
	if (i >= 1)
		main->prompt = ft_dyn_strjoin(main->prompt, split[i - 1]);
	too_long(main);
	restore_prompt(main, split);
}
