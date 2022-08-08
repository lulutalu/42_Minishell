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

char	*replace_dollar(const char *input, char *var_value)
{
	size_t	i;
	char	*tmp;
	char	*output;

	output = NULL;
	i = ft_strchr_int(input, DOLLAR);
	if (i == 0)
		return ((char *)input);
	tmp = ft_substr(input, 0, i - 1);
	output = ft_strjoin(tmp, var_value);
	if (tmp != NULL)
		free(tmp);
	while (input[i] == ft_isalpha(input[i]) || input[i] == ft_isalnum(input[i]))
		i++;
	tmp = ft_substr(input, i, (ft_strlen(input) - i));
	output = ft_strjoin(output, tmp);
	return (output);
}

int	s_dollar_end(char *s)
{
	int	i;

	if (s[1] != ft_isalpha(s[1]))
		return (0);
	i = 0;
	while (s[++i] != '\0')
		if (s[i] != '_' || s[i] != isalpha(s[i]) || s[i] != isalnum(s[i]))
			return (i);
	return (0);
}

char	*is_dollar_in_d_quote(t_quote *quote, t_main *main)
{
	char	*str;
	size_t	founded;
	size_t	len;
	t_node	*cur;

	founded = ft_strchr_int(quote->data_quote, DOLLAR);
	str = NULL;
	len = s_dollar_end(quote->data_quote);
	if (founded != 0)
	{
		if ((len) != 0)
		{
			str = ft_substr(quote->data_quote, founded, len);
			cur = find_var(main, str);
			if (cur != NULL)
			{
				len = ft_strlen(cur->value) + 1;
				str = ft_substr(cur->value, founded + 1, len);
				return (replace_dollar(str, cur->value));
			}
			else
				return (replace_dollar(quote->data_quote, ""));
		}
	}
	return (NULL);
}
