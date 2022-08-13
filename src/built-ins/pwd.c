/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:35:49 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/13 21:09:00 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*I guess it's self-explanatory how this works*/
/*Note for parsing : even with arguments, pwd should still work as default*/
int	b_pwd(t_main *main)
{
	char	pwd[4096];

	getcwd(pwd, 4096);
	if (main->proc.ncmd == 1 && main->fd.outfile > 1)
		ft_putendl_fd(pwd, main->fd.outfile);
	else
		ft_putendl_fd(pwd, STDOUT);
	g_exit_status = 0;
	return (0);
}
