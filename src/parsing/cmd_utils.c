//
// Created by Lowell Zima on 7/24/22.
//

#include "./../../includes/minishell.h"
#include "parsing.h"
#include <fcntl.h>
#include <unistd.h>


int is_bin(char *word)
{
	char *path;

	path = ft_strjoin("/bin/", word);
	if (access(path, X_OK) == 0)
	{
		free(path);
		return (1);
	}
	free(path);
	return (0);
}

char *cmd_saving(const char *input, t_cell *cell, size_t i)
{
	char *check;

	//TODO separator better than ft_strchr

	check = ft_strtrim(input, " ");
	if (ft_strncmp(check, "cd", 2) == 0)
	{
		cell->token = T_BUILT_IN;
		cell->data = ft_strdup("cd");
		cell->pos = i;
		if(ft_strchr(check, ' ') != NULL)
			return(ft_strchr(check, ' '));
	}
	if (ft_strncmp(check, "pwd", 3) == 0)
	{
		cell->token = T_BUILT_IN;
		cell->data = ft_strdup("pwd");
		cell->pos = i;
		if(ft_strchr(check, ' ') != NULL)
			return(ft_strchr(check, ' '));
	}
	if (ft_strncmp(check, "export", 6) == 0)
	{
		cell->token = T_BUILT_IN;
		cell->data = ft_strdup("export");
		cell->pos = i;
		if(ft_strchr(check, ' ') != NULL)
			return(ft_strchr(check, ' '));
	}
	if (ft_strncmp(check, "unset", 5) == 0)
	{
		cell->token = T_BUILT_IN;
		cell->data = ft_strdup("unset");
		cell->pos = i;
		if(ft_strchr(check, ' ') != NULL)
			return(ft_strchr(check, ' '));
	}
	if (ft_strncmp(check, "env", 3) == 0) {
		cell->token = T_BUILT_IN;
		cell->data = ft_strdup("env");
		cell->pos = i;
		if (ft_strchr(check, ' ') != NULL)
			return (ft_strchr(check, ' '));
	}
	if (ft_strncmp(check, "exit", 4) == 0) {
		cell->token = T_BUILT_IN;
		cell->data = ft_strdup("exit");
		cell->pos = i;
		if (ft_strchr(check, ' ') != NULL)
			return (ft_strchr(check, ' '));

	}
	else
		return(NULL);
}

//char *check_alpha(const char *input, t_cell *cell, size_t i)
//{
//
//}