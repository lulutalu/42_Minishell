/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo && lzima				            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:21:59 by lduboulo          #+#    #+#             */
/*   Updated: 2022/06/05 18:59:06 by lduboulo         ###   ########.fr       */
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
# include <stdlib.h>		/* malloc, free, exit, getenv */
# include <unistd.h>		/* access, getcwd, chdir, unlink, pipe's, tty's*/
# include <fcntl.h>		/* open */
# include <sys/types.h>		/* read | wait, waitpid, wait3, wait4 */
# include <sys/uio.h>		/* read */
# include <sys/wait.h>		/* wait, waitpid, wait3, wait4 */
# include <sys/time.h>		/* wait, waitpid, wait3, wait4 */
# include <sys/resource.h>	/* wait, waitpid, wait3, wait4 */
# include <signal.h>		/* signal, sigaction, sigemptyset, sigaddset,kill */
# include <sys/stat.h>		/* stat, lstat, fstat */
# include <dirent.h>		/* opendir, readdir, closedir */
# include <sys/ioctl.h>		/* ioctl */
# include <termios.h>		/* tcsetattr, tcgetattr */
# include <curses.h>		/* tgetent, tgetflag,tgetnum,tgetstr,tgoto, tputs */
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

typedef struct s_node
{
	char			*var;
	char			*value;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;



typedef struct s_main
{
	char	*prompt;
	char	*input;
	char	*res;
	t_node	*head_env;
	t_node	*tail_env;
}				t_main;

/*
 * Functions Declaration
*/

void		prompt_creation(t_main *main);

/*
 * Builts-Ins
*/

void		b_echo(t_main *main);
void		b_cd(t_main *main);
void		b_pwd(void);

/*
 * Parsing
*/

<<<<<<< Updated upstream
void		simple_quote(t_main *main);
int			n_quote(t_main *main);
void		memory_flush(char **tmp, char ***split);
=======
int		parser_launcher(char *input);
>>>>>>> Stashed changes

/*
 * Environment
*/

// Duplication of envp variable to have a env that can be modified
void		env_dup(t_main *main, char **envp);
void		lst_add(t_node **head_env, t_node **tail, char *str);
void		lst_del(t_main *main, t_node *cur);
void		lst_replace(t_main *main, char *var);
t_node		*find_var(t_main *main, char *var);

/*
 * Memory Functions
*/

void		alloc_check(void *ptr);

#endif