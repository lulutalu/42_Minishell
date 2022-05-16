/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:22:13 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/01 22:37:16 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordnumber(char const *s, char c)
{
	int	is;
	int	word;

	is = 0;
	word = 0;
	while (s[is] != '\0')
	{
		if (s[is] != c)
		{
			word++;
			while (s[is] != c && s[is] != '\0')
				is++;
		}
		if (s[is] != '\0')
			is++;
	}
	return (word);
}

int	findlen(char const *s, char c)
{
	int	is;
	int	len;

	is = 0;
	len = 0;
	while (s[is] != c && s[is] != '\0')
	{
		is++;
		len++;
	}
	return (len);
}

int	findstart(char const *s, char c)
{
	int	is;
	int	res;

	is = 0;
	res = 0;
	while (s[is] == c && s[is] != '\0')
		is++;
	res = is;
	return (res);
}

char	*filler(char const *s, char *tofill, char c)
{
	int	is;
	int	itofill;

	is = 0;
	itofill = 0;
	while (s[is] != c && s[is] != '\0')
		tofill[itofill++] = s[is++];
	tofill[itofill] = '\0';
	return (tofill);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		is;
	int		word;
	int		start;

	if (s == NULL)
		return (NULL);
	res = ft_calloc((wordnumber(s, c) + 1), sizeof(char *));
	if (res == NULL)
		return (NULL);
	is = 0;
	word = 0;
	while (wordnumber(s, c) > word)
	{
		is += findstart(s + is, c);
		start = is;
		res[word] = ft_calloc((findlen(s + is, c) + 1), sizeof(char));
		if (res[word] == NULL)
			return (NULL);
		is = start;
		res[word] = filler(s + is, res[word], c);
		is += ft_strlen(res[word]);
		word++;
	}
	return (res);
}
