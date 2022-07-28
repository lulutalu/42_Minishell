//
// Created by Lowell Zima on 6/1/22.
//

#include "./../../includes/minishell.h"

/* -- ascii -- */

typedef enum e_token
{
	T_D_QUOTE = '"',
	T_S_QUOTE = '\'',
	T_CMD = 999,
	T_ARG = 998,
	T_BUILT_IN = 997,
	T_DOLLAR = '$',
}	t_token;

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

typedef struct s_quote
{
	size_t				start;
	size_t 				i;
	char 				*data_quote;
	char				*tmp;
}				t_quote;

typedef struct s_cell
{
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

/* --- parser_main.c --- */
void 	parser_main_quote(char *ret);
size_t	reader(const char *input, t_cell *cell, size_t i, size_t len);
int		ft_isprint_without_space(int c);
void	print_list(t_network *list);

/* --- cell_utils.c --- */
t_quote		*init_quote(void);
t_cell		*init_cell(void);
t_network 	*init_network(void);
t_network	*set_network();
t_cell		*add_node(t_network *list);

/* --- parser_utils.c --- */
int		error_message(char *message);
//void	free_network(t_network *list);

/* --- quote_utils.c --- */
size_t	quote_saving(const char *input, size_t len, t_cell *cell, size_t i);
size_t	check_by_type_quote(const char *input, t_cell *cell, int type);
void	stock_quote_data(const char *input, t_quote *quote, size_t end, int type);

/* --- cmd_utils.c --- */
size_t cmd_saving(const char *input, size_t len, t_cell *cell, size_t i);
size_t find_separators(const char *input, size_t i);
size_t pipe_saving(t_cell *cell, int type, size_t i);

/* --- redirection_utils.c --- */
size_t t_redirection_output(const char *input, t_cell *cell, int token, size_t i);
size_t t_redirection_input(const char *input, t_cell *cell, int token, size_t i);