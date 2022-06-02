/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:26:47 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/02 19:14:52 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	b_cd(t_main *main)
{
	int		tilde;									//simple boolean
	int		status;
	char	*path;

	tilde = 0;
	path = NULL;
	if (ft_strchr(main->input, '~') != NULL || ft_strlen(main->input) == 0)//check for tilde
		tilde = 1;					//cd w/o args equal "cd ~"
	if (tilde == 1)
	{
		path = ft_strjoin(getenv("HOME"), "/");//'~' equal $HOME
		if (ft_strlen(main->input) > 1)	//condition to avoid pointer algebra if string too small
			path = ft_dyn_strjoin(path, main->input + 2);//add rest of command ex : cd ~/Downloads/
		status = chdir(path);
		free(path);
	}
	else
		status = chdir(main->input);
	if (status < 0)
		error_cd(main);
	else
		g_exit_status = 0;
}

void	error_cd(t_main *main)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(main->input, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	g_exit_status = 1;
}
