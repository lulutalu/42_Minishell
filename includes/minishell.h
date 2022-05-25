/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo && lzima				            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:21:59 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/25 11:45:48 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
 * Default Library
*/

# include "minishell.h"
# include "utils.h"

/*
 * Authorized Functions Library
*/

# include <stdio.h>		/* printf, strerror, perror, readline */
# include <stdlib.h>	/* malloc, free, exit, getenv */
# include <unistd.h>	/* access, getcwd, chdir, unlink, pipe's, tty's*/
# include <fcntl.h>		/* open */
# include <sys/types.h>	/* read */
# include <sys/uio.h>	/* read */
# include <sys/wait.h>	/* wait, waitpid, wait3, wait4 */
# include <signal.h>	/* signal, sigaction, sigemptyset, sigaddset, kill */
# include <sys/stat.h>	/* stat, lstat, fstat */
# include <dirent.h>	/* opendir, readdir, closedir */
# include <sys/ioctl.h>	/* ioctl */
# include <termios.h>	/* tcsetattr, tcgetattr */
# include <curses.h>	/* tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs */
# include <term.h>		/* tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs */

/*
 * Readline library
*/

# include <readline/readline.h>
# include <readline/history.h>

/*
 * Error And Messages Handling
*/

# define N_ARGS "\e[1;31mError, this binary doesn't accept arguments\n\e[0m"

/*
 * Global Variables
*/

extern int	g_exit_status;

/*
 * Structures
*/

typedef struct s_echo
{
	char	*cmd;
}				t_echo;

typedef struct s_main
{
	char	*prompt;
	char	*input;
}				t_main;

/*
 * Functions Declaration
*/

void	prompt_creation(t_main *main);

/*
 * Builts-Ins
*/

void	built_ins_echo(t_main *main, char **input);
void	built_ins_exit();
void	built_ins_pwd();
void	built_ins_unset();

#endif
