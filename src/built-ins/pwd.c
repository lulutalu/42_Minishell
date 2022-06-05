/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:35:49 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/05 18:58:55 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*I guess it's self-explanatory how this works*/
/*Note for parsing : even with arguments, pwd should still work as default*/
void	b_pwd(void)
{
	char	pwd[4096];

	getcwd(pwd, 4096);
	ft_putendl_fd(pwd, 1);
	g_exit_status = 0;
}
