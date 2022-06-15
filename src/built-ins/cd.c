/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:26:47 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/09 18:35:07 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*static functions means they're only existing 
for other functions of this file*/

/*need to check cmd like "cd ~/Downloads ../Desktop" <---- this should cd to
~/Downloads and void the '../Desktop' argument*/

/*Updating the environnment variables impacted by PWD*/
/*OLDPWD and PWD. Note that OLDPWD is used for "cd -"*/

static void	change_env_cd(t_main *main, char *old_pwd)
{
	char	new_pwd[4096];

	getcwd(new_pwd, 4096);
	lst_replace(main, ft_strjoin("PWD=", new_pwd));
	lst_replace(main, ft_strjoin("OLDPWD=", old_pwd));
}

/*Function that checks if chdir call was successful or not*/
/*In case it's not, error message is print and env variables are not changed*/
/*In case it's successful, env variables are changed*/
/*Also, global variables g_exit_status is updated each time*/
static void	check_exec_cd(t_main *main, char *path, int status, char *old_pwd)
{
	if (status != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		g_exit_status = 1;
	}
	else
	{
		g_exit_status = 0;
		change_env_cd(main, old_pwd);
	}
}

/*This function is used when env variables HOME is called*/
/*Usually, it's the case when '~' is called in arguments*/
/*Special cases : no arguments and "--" argument*/
static void	tilde_cd(t_main *main, char *old_pwd, char *input)
{
	int		status;
	char	*path;
	t_node	*cur;

	cur = find_var(main, "HOME");
	if (cur != NULL)
	{
		path = ft_strjoin(cur->value, "/");
		if (ft_strlen(input) > 1)
			path = ft_dyn_strjoin(path, input + 2);
		status = chdir(path);
		check_exec_cd(main, path, status, old_pwd);
		free(path);
	}
}

/*This function is used when env variables OLDPWD is called*/
/*The argument for this one is '-'. That equal to OLDPWD variable*/
static void	dash_cd(t_main *main, char *old_pwd)
{
	int		status;
	t_node	*cur;

	cur = find_var(main, "OLDPWD");
	if (cur != NULL)
	{
		status = chdir(cur->value);
		if (status == 0)
			ft_putendl_fd(cur->value, 1);
		check_exec_cd(main, cur->value, status, old_pwd);
	}
}

/*This is the main function of cd built-in*/
/*It's primary job is to decide which case we need to use*/
/*It check if it's "HOME" "OLDPWD" and also if it's neither of them*/
void	b_cd(t_main *main)
{
	int		status;
	char	actual_pwd[4096];
	char	*input;

	input = cmd_input(main);
	getcwd(actual_pwd, 4096);
	if (input[0] == '~' || ft_strlen(input) == 0 || \
			ft_strncmp(input, "--", 3) == 0)
		tilde_cd(main, actual_pwd, input);
	else if (ft_strncmp(input, "-", 2) == 0)
		dash_cd(main, actual_pwd);
	else
	{
		status = chdir(input);
		check_exec_cd(main, input, status, actual_pwd);
	}
	free(input);
}
