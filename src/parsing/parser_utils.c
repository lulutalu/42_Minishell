//
// Created by Lowell Zima on 6/1/22.
//
#include "./../../includes/minishell.h"


void	free_alloc(t_cell *c)
{
	free(c->mlx);
	free(c->complex);
	free(c);
	exit(1);
}

t_cell	*cell_mem_alloc(void)
{
	t_cell	*tmp;

	tmp = (t_cell *) malloc(sizeof(t_cell));
	if (tmp == NULL)
		return (NULL);
	tmp->quote = (t_quote *)malloc(sizeof(t_quote));
	tmp->node = (t_node *)malloc(sizeof(t_node));
	if (!tmp->quote || !tmp->node)
		return (NULL);
	return (tmp);
}

int	message(char *message)
{
	write(2, message, ft_strlen(message));
	return (1);
}

void	error_message(char *message)
{
	perror(message);
	exit(1);
}
