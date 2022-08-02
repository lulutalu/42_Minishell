/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:42:40 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/02 19:48:21 by lduboulo         ###   ########.fr       */
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
 * Defined (messages, token, ...)
*/

# define N_ARGS "\e[1;31mError, this binary doesn't accept arguments\n\e[0m"

/*Those define are used for easier manipulation of in and out of pipes*/
# define PIPE_IN 1
# define PIPE_OUT 0
# define STDIN 0
# define STDOUT 1

/* --  | token -- */
#define PIPE			124

/* -- ' ' token -- */
#define SPACE			32

/* --  ' && " token -- */
#define S_QUOTE			39
#define D_QUOTE			34

/* --  < && << token -- */
#define S_TO_BIG		60
#define RE_INPUT		997
#define D_RE_INPUT		996

/* -- > && >> token -- */
#define BIG_TO_S		62
#define RE_OUTPUT		995
#define D_RE_OUTPUT		994

/* -- > $ token -- */
#define DOLLAR			36

/*
 * Global Variables
*/

extern int	g_exit_status;

/*
 * Structures
*/

typedef enum e_token
{
	T_D_QUOTE = '"',
	T_S_QUOTE = '\'',
	T_CMD = 999,
	T_DOLLAR = '$',
}	t_token;

typedef struct s_quote
{
	size_t				start;
	size_t 				i;
	char 				*data_quote;
	char				*tmp;
}				t_quote;

typedef struct s_cell
{
	int					pos;
	t_token				token; /*T_D_QUOTE*/
	int 				type;
	size_t				start;   /* index de input trouvé */
	size_t 				end;
	char 				**dollar_material; /* $test$lol Splitted */
	char				*data; /* "103" */
	char 				*ret;
	struct s_cell		*next;
//	struct s_cell		*prev;
	t_quote				*quote;
}				t_cell;

typedef struct s_network
{
	t_cell		*head_cell;
	t_cell		*current_cell;
	t_cell		*tail_cell;
}				t_network;

typedef struct s_node
{
	char			*var;
	char			*value;
	int				sort_pos;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_proc
{
	int		ncmd;
	int		npipe;
	pid_t	pid;
}				t_proc;

typedef struct s_fd
{
	int	infile;
	int	outfile;
	int	input;
	int	output;
	int	here_doc[2];
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
	t_proc				proc;
	t_fd				fd;
	t_node				*head_env;
	t_node				*tail_env;
	t_network			list;
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

int			redirect_input(t_main *main, t_cell *cur);
int			redirect_output(t_main *main, t_cell *cur);
int			redirect_double_output(t_main *main, t_cell *cur);
int			here_doc(t_main *main, t_cell *cur);

/*
 * Parsing
*/

/* --- parser_main.c --- */

int 		parser_main_quote(char *ret, t_main *main);
size_t		reader(const char *input, t_cell *cell, size_t i, size_t len);
int			ft_isprint_without_space(int c);
void		print_list(t_network *list);
int			check_input(t_main *main);

/* --- cell_utils.c --- */

t_quote		*init_quote(void);
t_cell		*init_cell(void);
t_network 	init_network(void);
t_network	set_network();
t_cell		*add_node(t_network *list);

/* --- parser_utils.c --- */

int			error_message(char *message);
//void	free_network(t_network *list);

/* --- quote_utils.c --- */

size_t		quote_saving(const char *input, size_t len, t_cell *cell, size_t i);
size_t		check_by_type_quote(const char *input, t_cell *cell, int type);
void		stock_quote_data(const char *input, t_quote *quote, size_t end, int type);

/* --- cmd_utils.c --- */

size_t		cmd_saving(const char *input, size_t len, t_cell *cell, size_t i);
size_t		find_separators(const char *input, size_t i);
size_t		pipe_saving(t_cell *cell, int type, size_t i);

/* --- redirection_utils.c --- */

size_t		t_redirection_output(const char *input, t_cell *cell, int token, size_t i);
size_t		t_redirection_input(const char *input, t_cell *cell, int token, size_t i);

/*
 * Execution
*/

void		control_tower(t_main *main);
void		cmd_listing(t_main *main);
int			launch_process(t_main *main, int icmd);
int			check_redirection(t_main *main, t_cell *cur, int icmd);

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
 * Error and Memory Failure verification
*/

int			check_for_error(int value);
void		alloc_check(void *ptr);

#endif
