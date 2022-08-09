/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:54:47 by lzima             #+#    #+#             */
/*   Updated: 2022/08/06 11:54:50 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minishell.h"

char	*replace_dollar(char *input, char *var_value)
{
	size_t	i;
	size_t 	len_input;
	char	*tmp;
	char	*output;

	len_input = ft_strlen(input);
	output = NULL;
	i = ft_strchr_int(input, DOLLAR);
	if (i < 0)
		return ((char *)input);
	tmp = ft_substr(input, 0, i);
	output = ft_strjoin(tmp, var_value);
	if (i++ < len_input)
		while (input[i] == ft_isalnum(input[i]))
				i++;
	tmp = ft_substr(input, i, len_input - i);
	output = ft_strjoin(output, tmp);
	return (output);
}

int	s_dollar_end(char *s, int i)
{
	while (s[++i] != '\0')
	{
		if (s[i] != ft_isalnum(s[i]) || s[i] == '_' || s[i] == '\0')
			return (i - 1);
	}
	return (-1);
}

char	*is_dollar_in_d_quote(t_quote *quote, t_main *main)
{
	char	*str;
	int 	founded;
	int 	len;
	t_node	*cur;

	founded = ft_strchr_int(quote->data_quote, '$');
	if (founded < 0)
		return (NULL);
	str = NULL;
	len = s_dollar_end(quote->data_quote, founded);
	if (founded >= 0)
	{
		if (len != 0)
		{
			str = ft_substr(quote->data_quote, founded + 1, len - founded);
			cur = find_var(main, str);
			if (cur != NULL)
			{
				return (replace_dollar(quote->data_quote, cur->value));
			}
			else
				return (replace_dollar(quote->data_quote, ""));
		}
	}
	return (NULL);
}
