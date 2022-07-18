//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"

#define T_D_QUOTE 3

int	char_dup(char *input, char data)
{
	char		*one;
	char 		*two;
	t_trigger	*trigger;

	//malloc trigger
	one = ft_strchr(input, data);
	if (one != NULL)
		trigger->one = 1;
	two = ft_strchr(one, data);
	if (two != NULL)
		trigger->two = 1;
	return (0);
}

char *stock_input(char *in, char *new_in)
{
	char	*ret;
	ret = ft_dyn_strjoin(in, new_in);
	return(ret);
}

int error_double_quotes_b_slash(char *input, t_cell *cell)
{
	char *in;
	char *stock;
	char *out;
	int i;

	while(1)
	{
		in = readline("> ");
		stock = ft_dyn_strjoin(input, in);
		i = 0;
		while (in[i])
		{
			if (in[i++] == D_QUOTE)
			{
				cell->token = T_D_QUOTE;
				cell->data = stock;
			}
		}
	}
}

int error_double_quotes(char *input)
{
	int		i;
	int		y;

	i = 0;
	while (input[i])
	{
		if (input[i] == D_QUOTE)
		{
			while (input[i])
			{
				if (input[i] == B_SLASH)
					error_double_quotes_b_slash(input);
				else if (input[i] == D_QUOTE)
					return(T_D_QUOTE);
				else
					return(ERROR);
			}
			i++;
		}
		i++;
	}
}



t_token *mem_alloc(t_token *token)
{
	token = (t_token *) malloc(sizeof(t_token));
	if(token == NULL)
		return (NULL);

	return (token);
}

t_token	*create_cell(char *input)
{
	cell = mem_alloc(cell);
}

char	**split_space(char *input, t_token *token)
{
	char 	**splited;
	int		i;

	splited = ft_split(input, SEMICOLON);
	while (splited[++i])
		token = add_cell(token, splited[i], i);
	return (splited);
}

int	parser_launcher(char *input)
{
	int i;
	t_token *token;

	i = -1;
	while(input[++i] != '\0')
	{
		id_check(input[i], id);
		id->indexs[i] = i;
	}
}


//void id_check(char c, t_id *id)
//{
//	if (ft_isdigit(c))
//		id->num = &c;
//	if (c <= 'A' || c >= 'Z')
//		id->alpha_up = &c;
//	if (c <= 'a' || c >= 'z')
//		id->alpha_down = &c;
//	if (c == S_QUOTE)
//		id->s_quote = &c;
//	if (c == D_QUOTE)
//		id->d_quote = &c;
//	if (c == SPACE)
//		;
//	if (c == B_SLASH)
//		id->b_slash = &c;
//	if (c == SLASH)
//		id->slash = &c;
//	if (c == S_TO_BIG)
//		id->s_to_big_chevron = &c;
//	if (c == BIG_TO_S)
//		id->big_to_s_chevron = &c;
//	if (c == ROUND_OPEN)
//		id->round_open = &c;
//	if (c == ROUND_CLOSE)
//		id->round_close = &c;
//	if (c == MONEY)
//		id->dollar = &c;
//}

//int	error_check(t_id *id)
//{
//	if (!id->s_to_big_chevron || !id->big_to_s_chevron)
//		;
//}
