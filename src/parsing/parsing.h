//
// Created by Lowell Zima on 6/1/22.
//

#include "./../../includes/minishell.h"

/* -- ascii -- */
#define ALPHA_UP 		1
#define ALPHA_DOWN 		2
#define NUM				3
#define S_QUOTE			39
#define D_QUOTE			34
#define SPACE_SEP		6
#define SPACE			32
#define B_SLASH			92
#define SLASH			47
#define S_TO_BIG		60
#define BIG_TO_S		62
#define ROUND_OPEN		40
#define ROUND_CLOSE		41
#define MONEY			36
#define SEMICOLON		59


/* -- "" && '' token -- */
#define T_D_QUOTE 		999
#define T_S_QUOTE 		998

/* --  < && << token -- */
#define RE_INPUT		997
#define D_RE_INPUT		996

/* -- > && >> token -- */
#define RE_OUTPUT		995
#define D_RE_OUTPUT		994

typedef struct s_quote
{
	int					start;
	int					type;
	char 				*data_quote;
}				t_quote;

typedef struct s_cell
{
	int					token; /*T_D_QUOTE*/
	int					pos;
	char				*data; /* "$PATH" */
	struct s_cell		*next;
	struct s_cell		*prev;
	t_quote				*quote;
}				t_cell;

typedef struct s_network
{
	t_cell		*head_cell;
	t_cell		*tail_cell;
}				t_network;

//typedef struct s_main
//{
//	char			*
//}				t_main;
//
//typedef struct s_id
//{
//	char *alpha_up;				/* 	ABCDEFGHIJKLMNOPQRSTUVWXYZ 					*/
//	char *alpha_down; 			/* 	abcdefghijklmnopqrstuvwxyz 					*/
//	char *num;					/* 	0123456789 									*/
//	char *s_quote;				/* 	' 											*/
//	char *d_quote;				/* 	" 											*/
//	char *space_separator;		/* 	\t \v \n \f \r 								*/
//	char *space;				/* 	' ' 										*/
//	char *b_slash;				/* 	\ 											*/
//	char *slash;				/* 	/ 											*/
//	char *s_to_big_chevron;		/* 	< 											*/
//	char *big_to_s_chevron;		/* 	> 											*/
//	char *round_open;			/* 	( 											*/
//	char *round_close;			/* 	) 											*/
//	char *dollar;				/* 	$											*/
//	int	 *indexs;
//}	t_id;
//

/* --- parser_main.c --- */
char	**parser_pipe(char *input);

/* --- cell_utils.c --- */
t_cell	*set_node(t_cell **node, t_network **network, char *av);
void connect_node(t_cell **node, t_cell **tmp, t_network **network);
t_cell	*init_cell(void);
t_quote	*init_quote(void);
void		print_list(t_network *list);

/* --- cell_utils.c --- */
//t_cell	*add_node(t_cell **cell, char **av);
//t_node_cell	*create_node(t_cell **cell, char **av, int i);
//t_node_cell	*init_node();
//t_node_cell	*create_cell(char *cell_input);
//t_cell	*add_cell(t_cell **cell, char **av, int ac);


/* --- parser_utils.c --- */

int	error_message(char *message);
void	free_alloc(t_cell *c);
t_cell	*cell_mem_alloc(void);
char	*ft_strreplace(const char *input, char *replace, char trigger);

/* --- quote_utils.c --- */
void	stock_quote_data(const char *input, t_quote *quote, int end);
int 	check_quote(const char *input, t_quote *quote, int quote_type);
char	*quote(const char *input, t_cell *cell);

/* --- redirection.c --- */
void	redirection(char *input, t_cell *cell);
int 	t_redirection_output(const char *input, t_cell *cell);
int 	t_redirection_input(const char *input, t_cell *cell);