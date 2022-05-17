/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:21:59 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/17 16:29:01 by lduboulo         ###   ########.fr       */
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

# include <stdio.h>		/* printf, strerror, perror */
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
