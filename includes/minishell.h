/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:42:40 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/27 18:25:21 by lduboulo         ###   ########.fr       */
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
void		rl_replace_line(const char *text, int clear_undo);

/*
 * Error And Messages Handling
*/

# define N_ARGS "\e[1;31mError, this binary doesn't accept arguments\n\e[0m"

/*Those define are used for easier manipulation of in and out of pipes*/
# define PIPE_IN 1
# define PIPE_OUT 0

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
	int				sort_pos;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_fd
{
	int	infile;
	int	outfile;
	int	io[2];
	int	new_io[2];
}				t_fd;

typedef struct s_main
{
	char				*prompt;
	char				*restore_prompt;
	char				*input;
	char				**input_split;
	char				*res;
	t_fd				fd;
	t_node				*head_env;
	t_node				*tail_env;
	struct sigaction	sa;
}				t_main;

/*
 * Minishell utils
*/

void		prompt_creation(t_main *main);
void		check_for_signals(t_main *main);

/*
 * Builts-Ins
*/

void		built_in(t_main *main);

char		*cmd_input(t_main *main);
void		b_echo(t_main *main);
void		b_cd(t_main *main);
void		b_pwd(void);
void		b_export(t_main *main);
void		b_env(t_main *main);
void		b_unset(t_main *main);
void		b_exit(t_main *main);

/*
 * Redirections
*/

void		redirection(t_main *main);

void		less_than(t_main *main);
void		double_less_than(t_main *main);
void		more_than(t_main *main);
void		more_than_double(t_main *main);

/*
 * Parsing
*/

void		simple_quote(t_main *main);
int			n_quote(t_main *main);
void		memory_flush(char **tmp, char ***split);
int			parser_launcher(char *input);
int			parser_launcher(char *input);

/*
 * Environment
*/

// Duplication of envp variable to have a env that can be modified
void		env_dup(t_main *main, char **envp);
void		lst_add(t_node **head_env, t_node **tail, char *str);
void		lst_del(t_main *main, t_node *cur);
void		lst_replace(t_main *main, char *var);
t_node		*find_var(t_main *main, char *var);
void		env_sort(t_main *main);
int			lst_size(t_main *main);

/*
 * Memory Functions
*/

void		alloc_check(void *ptr);

#endif
