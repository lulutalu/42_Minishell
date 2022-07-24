//
// Created by Lowell Zima on 6/1/22.
//

#include "./../../includes/minishell.h"

/* -- ascii -- */
#define ALPHA_UP 		1
#define ALPHA_DOWN 		2
#define NUM				3
#define PIPE			124
#define S_QUOTE			39
#define D_QUOTE			34

#define SPACE			32
#define B_SLASH			92
#define SLASH			47
#define S_TO_BIG		60
#define BIG_TO_S		62
#define ROUND_OPEN		40
#define ROUND_CLOSE		41
#define DOLLAR			36
#define SEMICOLON		59

typedef enum e_token
{
	T_D_QUOTE = '"',
	T_S_QUOTE = '\'',
	T_CMD = 999,
	T_ARG = 998,
	T_BUILT_IN = 997,
}	t_token;

/* -- "" && '' token --
#define T_D_QUOTE 		999
#define T_S_QUOTE 		998
*/
/* --  < && << token -- */
#define RE_INPUT		997
#define D_RE_INPUT		996

/* -- > && >> token -- */
#define RE_OUTPUT		995
#define D_RE_OUTPUT		994

/* -- > && >> token -- */
#define BUILT_IN		993

typedef struct s_quote
{
	size_t				start;
	size_t 				i;
	int					type;
	int 				s_quote;
	int 				d_quote;
	char 				*data_quote;
	char				*tmp;
}				t_quote;

typedef struct s_cell
{
	t_token				token; /*T_D_QUOTE*/
	size_t				pos;   /* index de input trouvé */
	size_t 				end;
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

/* --- parser_main.c --- */
char *parser_main_quote(char *ret);
void parser_pipe(char *saved_ret);

/* --- cmd_utils.c --- */
char *cmd_saving(const char *input, t_cell *cell, size_t i);

/* --- cell_utils.c --- */
//t_cell		*set_node(t_cell **node, t_network **network, char *av);
//void 		connect_node(t_cell **node, t_cell **tmp, t_network **network);
t_cell		*init_cell(void);
t_quote		*init_quote(void);
void		print_list(t_network *list);

/* --- parser_utils.c --- */

int			error_message(char *message);
//void		free_alloc(t_cell *c);
//t_cell	*cell_mem_alloc(void);
char		*ft_strreplace(const char *input, char *replace, char trigger);
char	*ft_strreplace_one_trigger(const char *input, char *replace, char one_trigger);

/* --- quote_utils.c --- */
int			stock_quote_data(const char *input, t_quote *quote, size_t end, int type);
int			second_quote_check_by_type_quote(t_cell *cell, int type, size_t i);
char		*quote_saving(t_cell *cell, int token, size_t i);
char		*check_saving(const char *input, t_cell *cell);
char 		*pipe_saving(t_cell *cell, int token, size_t i);

/* --- redirection.c --- */
char *redirection_saving(t_cell *cell, int type, size_t i);
char *t_redirection_output(const char *input, t_cell *cell, int token, size_t i);
char *t_redirection_input(const char *input, t_cell *cell, int token, size_t i);