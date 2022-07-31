/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:40:01 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/31 17:56:25 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_for_arg(char *input, char sep)
{
	char	*str;
	int		i;

	str = ft_strchr(input, sep) + 1;
	if (str[0] == sep)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	g_exit_status = 1;
	ft_putendl_fd("minishell: syntax error near unexpected token", 2);
	return (0);
}

void	less_than(t_main *main)
{
	char	*filepath;
	char	**split;
	int		res;

	res = check_for_arg(main->input, '<');
	if (res == 1)
	{
		split = ft_split(ft_strchr(main->input, '<') + 1, ' ');
		filepath = ft_strdup(split[0]);
		ft_tab_free((void **)split);
		main->fd.infile = open(filepath, O_RDONLY);
		if (main->fd.infile < 0)
		{
			g_exit_status = 1;
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(filepath, 2);
			ft_putstr_fd(": ", 2);
			perror("");
		}
	}
	if (res == -1)
		double_less_than(main);
}

void	double_less_than(t_main *main)
{
	char	*buffer;
	char	**split;
	char	*delimiter;
	char	*here_doc;

	buffer = ft_calloc(1, sizeof(char));
	split = ft_split(ft_strchr(main->input, '<') + 2, ' ');
	delimiter = ft_strjoin(split[0], "\n");
	ft_tab_free((void **)split);
	here_doc = NULL;
	while (1)
	{
		ft_putstr_fd("> ", 1);
		buffer = get_next_line(0);
		if (ft_strncmp(buffer, delimiter, ft_strlen(buffer)) != 0)
		{
			if (!here_doc)
				here_doc = ft_strdup(buffer);
			else
				here_doc = ft_dyn_strjoin(here_doc, buffer);
			free(buffer);
		}
		else
		{
			free(buffer);
			break ;
		}
	}
}

/*Can't output in multiple files but the redirection can happen in the
 * Middle of any command. ex : echo > test "Salut" should redirect
 * the command echo "Salut" into a file named test*/
/*For now, without the parsing part that operation will not work
 * The reason is that the built-ins are not using the correct input*/
void	more_than(t_main *main)
{
	char	*filepath;
	char	**split;
	int		res;

	res = check_for_arg(main->input, '>');
	if (res == 1)
	{
		split = ft_split(ft_strchr(main->input, '>') + 1, ' ');
		filepath = ft_strdup(split[0]);
		ft_tab_free((void **)split);
		main->fd.outfile = open(filepath, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (main->fd.outfile < 0)
		{
			g_exit_status = 1;
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(filepath, 2);
			ft_putstr_fd(": ", 2);
			perror("");
		}
	}
	if (res == -1)
		more_than_double(main);
}

void	more_than_double(t_main *main)
{
	char	*filepath;
	char	**split;

	split = ft_split(ft_strchr(main->input, '>') + 2, ' ');
	filepath = ft_strdup(split[0]);
	ft_tab_free((void **)split);
	main->fd.outfile = open(filepath, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (main->fd.outfile < 0)
	{
		g_exit_status = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(filepath, 2);
		ft_putstr_fd(": ", 2);
		perror("");
	}
}
