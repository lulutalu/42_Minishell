/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:57:33 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/24 15:22:25 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_bzero(void *s, size_t n)
{
	int	is;

	is = 0;
	while (n-- > 0)
		((char *)s)[is++] = '\0';
	return (s);
}

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strjoin(char **s1, char const *s2)
{
	char	*res;
	int		i1;
	int		i2;
	int		ires;

	ires = 0;
	if (s2 == NULL)
		return (NULL);
	res = malloc((gnl_strlen(*s1) + (gnl_strlen(s2) + 1)) * sizeof(char));
	if (! res)
		return (NULL);
	gnl_bzero(res, ((gnl_strlen(*s1) + gnl_strlen(s2) + 1) * sizeof(char)));
	i1 = 0;
	while ((*s1)[i1] != '\0')
		res[ires++] = (*s1)[i1++];
	i2 = 0;
	while (s2[i2] != '\0')
		res[ires++] = s2[i2++];
	res[ires] = '\0';
	free(*s1);
	return (res);
}

char	*gnl_strdup(char **s1, int istr)
{
	char	*copy;
	int		icopy;

	icopy = 0;
	copy = malloc((gnl_strlen(*s1) + 1) * sizeof(char));
	if (! copy)
		return (NULL);
	gnl_bzero(copy, (gnl_strlen(*s1) + 1) * sizeof(char));
	while ((*s1)[istr] != '\0')
		copy[icopy++] = (*s1)[istr++];
	copy[icopy] = '\0';
	free(*s1);
	return (copy);
}

char	**gnl_substr(char **substr, char **s, unsigned int start, size_t len)
{
	size_t	isub;

	isub = 0;
	if (*s == NULL)
		return (NULL);
	else if (start > gnl_strlen(*s))
		return (NULL);
	else if ((gnl_strlen(*s) - start) < len)
		*substr = malloc((gnl_strlen(*s) - start + 1) * sizeof(char));
	else
		*substr = malloc((len + 1) * sizeof(char));
	if (! *substr)
		return (NULL);
	while (isub < len && (*s)[start] != '\0')
		(*substr)[isub++] = (*s)[start++];
	(*substr)[isub] = '\0';
	return (substr);
}
