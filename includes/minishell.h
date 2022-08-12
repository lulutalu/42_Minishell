/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:42:40 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/12 14:59:15 by lduboulo         ###   ########.fr       */
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
# define PIPE			124

/* -- ' ' token -- */
# ifndef SPACE
#  define SPACE			32
# endif
/* --  ' && " token -- */
# define S_QUOTE			39
# define D_QUOTE			34

/* --  < && << token -- */
# define S_TO_BIG		60
# define RE_INPUT		997
# define D_RE_INPUT		996

/* -- > && >> token -- */
# define BIG_TO_S		62
# define RE_OUTPUT		995
# define D_RE_OUTPUT		994

/* -- > $ token -- */
# define DOLLAR			36

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
	size_t				i;
	int					type;
	int					error;
	char				*data_quote;
	char				*tmp;
}				t_quote;

typedef struct s_cell
{
	int					pos;
	t_token				token;
	int					type;
	size_t				start;
	size_t				end;
	int					error;
	char				**dollar_material;
	char				*data;
	struct s_cell		*next;
	struct s_cell		*prev;
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
	pid_t	*pid;
	int		status;
}				t_proc;

typedef struct s_fd
{
	int	infile;
	int	outfile;
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
	char				**env;
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
void		struct_init(t_main *main);
void		main_operation(t_main *main);

/*
 * Builts-Ins
*/

char		*cmd_input(t_main *main);
void		b_echo(t_main *main);
int			b_cd(t_main *main, t_cell *cur, int icmd);
void		b_pwd(void);
void		b_export(t_main *main);
void		b_env(t_main *main);
void		b_unset(t_main *main);
int			b_exit(t_main *main, t_cell *cur, int icmd);

void		exit_free(t_main *main);
t_cell		*avoid_redir(t_cell *cur, int icmd);

/*
 * Redirections
*/

int			redirect_input(t_main *main, t_cell *cur);
int			redirect_output(t_main *main, t_cell *cur);
int			redirect_double_output(t_main *main, t_cell *cur);
int			here_doc(t_main *main, t_cell *cur);
int			main_here_doc(t_main *main, t_cell *cur);

/*
 * Parsing
*/

/* --- parser_main.c --- */

int			parser_main_quote(char *ret, t_main *main);
size_t		reader(char *input, t_cell *cell, t_main *main, size_t i);
int			ft_isprint_without_space(int c);
void		print_list(t_network *list);
int			check_input(t_main *main);

/* --- cell_utils.c --- */

t_quote		*init_quote(void);
t_cell		*init_cell(void);
t_network	init_network(void);
t_network	set_network(void);
t_cell		*add_node(t_network *list);

/* --- parser_utils.c --- */

int			error_message(char *message);
void		free_quote(t_quote *quote);
int			ft_strchr_int(const char *s, int c);
//void	free_network(t_network *list);

/* --- quote_utils.c --- */

size_t		quote_saving(char *input, t_cell *cell, t_main *main, size_t i);
size_t		check_by_type(char *input, t_cell *cell, t_main *main, int type);
void		quote_data(char *input, t_quote *quote, t_main *main, size_t end);

/* --- dollar_utils.c --- */

char		*replace_dollar(char *input, char *var_value);
int			s_dollar_end(char *s, int i);
char		*is_dollar_in_d_quote(t_quote *quote, t_main *main);

/* --- cmd_utils.c --- */

size_t		cmd_saving(const char *input, t_cell *cell, size_t i, t_main *main);
size_t		find_separators(const char *input, size_t i);
size_t		pipe_saving(t_cell *cell, int type, size_t i);
void		dollar_data(t_cell *cell, t_main *main);

/* --- redirection_utils.c --- */

size_t		t_re_output(const char *input, t_cell *cell, int token, size_t i);
size_t		t_re_input(const char *input, t_cell *cell, int token, size_t i);

/*
 * Execution
*/
void		parent_operation(t_main *main, int icmd);
int			is_built_ins(t_main *main, t_cell *cur, int icmd);
void		control_tower(t_main *main);
void		wait_process(t_main *main, int icmd);
void		cmd_listing(t_main *main);
int			launch_process(t_main *main, int icmd);
void		clear_fd(t_main *main);
int			check_redirection(t_main *main, t_cell *cur, int icmd);

void		exec(t_main *main, int icmd);
char		**get_path(t_main *main);
char		**get_args(t_main *main, int icmd);
int			n_args(t_cell *cur, int icmd);
void		command_not_found(char *command);

/*
 * Child and processes
*/

int			child_process(t_main *main, int icmd);
int			open_pipe(t_main *main, int icmd);
void		who_do_i_dup(t_main *main, int icmd);
int			is_forked_built_ins(t_main *main, int icmd);

void		only_pipe(t_main *main, int icmd);
void		dup_input(t_main *main, int icmd);
void		dup_here_doc(t_main *main, int icmd);
void		dup_output(t_main *main, int icmd);
void		dup_input_and_output(t_main *main);
void		dup_here_doc_and_output(t_main *main);

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
void		tab_format_env(t_main *main);

/*
 * Error and Memory Failure verification
*/

void		check_for_error_fork(int value);
int			check_for_error(int value);
void		alloc_check(void *ptr);
int			fd_not_valid(char *filename);
void		exit_error(int value);

#endif
