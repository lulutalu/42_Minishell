//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"


t_token *mem_alloc(t_token *token)
{
	token = (t_token *) malloc(sizeof(t_token));
	if(token == NULL)
		return (NULL);

	return (token);
}

t_token	*create_token(char *input)
{
	token = mem_alloc(token);
}

char	**split_semicolon(char *input, t_token *token)
{
	char **splited;

	splited = ft_split(input, SEMICOLON);
	while (splited[++i])
		token = add_token(token, splitted[i], i);
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
