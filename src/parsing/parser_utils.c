//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"
#include "parsing.h"
//
//void	free_alloc(t_cell *c)
//{
//	if (c->head_cell != NULL)
//		free(c->head_cell);
//	if (c->tail_cell != NULL)
//		free(c->tail_cell);
//	if (c->quote != NULL)
//		free(c->quote);
//	free(c);
//	exit(1);
//}
//
//t_cell	*cell_mem_alloc(void)
//{
//	t_cell	*tmp;
//
//	tmp = (t_cell *) malloc(sizeof(t_cell));
//	if (tmp == NULL)
//		return (NULL);
//	tmp->quote = (t_quote *)malloc(sizeof(t_quote));
//	tmp->tail_cell = (t_node_cell *)malloc(sizeof(t_node_cell));
////	tmp->head_cell = (t_node_cell *)malloc(sizeof(t_node_cell));
//	tmp->head_cell = NULL;
//	if (!tmp->quote || !tmp->tail_cell)
//		return (NULL);
//	return (tmp);
//}

int	error_message(char *message)
{
	write(2, message, ft_strlen(message));
	exit (1);
}

/* keeping start trigger and keep rest of the string as it is */

static char *check_trigger(const char *input, int i, char trigger)
{
	char *ret;
	int tmp_i;
	int saved_i;
	size_t len;

	saved_i = i;
	tmp_i = i;
	ret = NULL;
	len = ft_strlen(input);
	while (input[++tmp_i])
		if (input[tmp_i] == trigger)
		{
			ret = ft_substr(input, tmp_i + 1, len);
			break ;
		}
	if (ret != NULL)
		return (ret);
	tmp_i = saved_i - 1;
	while (input[++tmp_i])
		if (input[i] == ' ')
			ret = ft_substr(input, tmp_i, len);
	return (ret);
}

char	*ft_strreplace_one_trigger(const char *input, char *replace, char one_trigger)
{
	int i;
	char *tmp;
	char *output;

	output = NULL;
	i = -1;
	while (input[++i])
	{
		if (input[i] == one_trigger) /* | */
		{
			tmp = ft_substr(input, 0, i);
			output = ft_strjoin(tmp, replace);
			if (tmp != NULL)
				free(tmp);
			tmp = ft_substr(input, i + 1, (ft_strlen(input) - i));
			output = ft_strjoin(output, tmp);
			return (output);
		}
	}
	return(NULL);
}

char	*ft_strreplace(const char *input, char *replace, char trigger)
{
	int i;
	char *tmp;
	char *output;

	output = NULL;
	i = -1;
	while (input[++i])
	{
		if (input[i] == trigger) /* ' */
		{
			tmp = ft_substr(input, 0, i);
			output = ft_strjoin(tmp, replace);
			if (tmp != NULL)
				free(tmp);
			tmp = check_trigger(input, i, trigger);
			if (tmp != NULL)
			{
				output = ft_strjoin(output, tmp);
				free(tmp);
			}
			break ;
		}
	}
	return(output);
}





	/* count until *char* -> strdup dans char **before
	 *
	*/

	/*
	 * echo "lol" >        test
	 *
	 * CMD   ARG  REDIRECT ARG
	 */
