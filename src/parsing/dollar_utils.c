/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:54:47 by lzima             #+#    #+#             */
/*   Updated: 2022/08/15 12:51:10 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

char	*replace_dollar(char *input, char *var_value)
{
	size_t	i;
	size_t	len_input;
	char	*tmp;
	char	*output;

	len_input = ft_strlen(input);
	output = NULL;
	i = ft_strchr_int(input, DOLLAR);
	if (i < 0)
		return ((char *)input);
	tmp = ft_substr(input, 0, i);
	output = ft_strjoin(tmp, var_value);
	to_be_free((void *)&tmp);
	if (i++ < len_input)
		while (input && input[i] != '$' && (input[i] == ft_isalnum(input[i]) \
					|| input[i] == '?' || input[i] == '_'))
				i++;
	tmp = ft_substr(input, i, len_input - i);
	output = ft_dyn_strjoin(output, tmp);
	to_be_free((void *)&tmp);
	to_be_free((void *)&input);
	return (output);
}

int	s_dollar_end(char *s, int i)
{
	while (s[++i] != '\0')
	{
		if (ft_isalnum(s[i]) == -1 && s[i] != '_' && s[i] != '?')
			return (i - 1);
	}
	return (-1);
}

char	*is_dollar_in_d_quote(t_quote *quote, t_main *main)
{
	int		founded;
	int		len;

	founded = ft_strchr_int(quote->data_quote, '$');
	if (founded < 0)
		return (NULL);
	len = s_dollar_end(quote->data_quote, founded);
	if (founded >= 0)
		if (len != 0)
			return (d_is_in_quote(quote, main, founded, len));
	return (NULL);
}

void	replace_dollar_data(t_cell *cell, t_main *main, int i)
{
	t_node	*cur;

	cur = find_var(main, cell->dollar_material[i]);
	if (cur != NULL)
	{
		free(cell->dollar_material[i]);
		cell->dollar_material[i] = ft_strdup(cur->value);
		cell->dollar_var = ft_strdup(cur->value);
	}
	else if (ft_strncmp(cell->dollar_material[i], "?", \
				ft_strlen(cell->dollar_material[i])) == 0)
	{
		free(cell->dollar_material[i]);
		cell->dollar_material[i] = ft_itoa(g_exit_status);
	}
	else
	{
		free(cell->dollar_material[i]);
		cell->dollar_material[i] = ft_strdup("");
	}
}

char	*d_is_in_quote(t_quote *quote, t_main *main, int founded, int len)
{
	char	*str;
	t_node	*cur;

	str = NULL;
	str = ft_substr(quote->data_quote, founded + 1, len - founded);
	cur = find_var(main, str);
	to_be_free((void *)&quote->dollar_var);
	quote->dollar_var = ft_strdup(str);
	if (cur != NULL)
	{
		free(str);
		return (replace_dollar(quote->data_quote, cur->value));
	}
	else if (ft_strncmp(str, "?", ft_strlen("?") + 1) == 0)
	{
		free(str);
		return (replace_dollar(quote->data_quote, ft_itoa(g_exit_status)));
	}
	else
	{
		free(str);
		return (replace_dollar(quote->data_quote, ""));
	}
}
