/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:49:10 by lduboulo          #+#    #+#             */
/*   Updated: 2021/11/01 15:25:02 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	startofstr(char const *s1, char const *set)
{
	int	istr;
	int	iset;
	int	start;

	start = 0;
	istr = 0;
	while (s1[istr] != '\0')
	{
		iset = 0;
		while (s1[istr] != set[iset] && set[iset] != '\0')
			iset++;
		if (s1[istr] == set[iset])
			istr++;
		else
		{
			start = istr;
			break ;
		}
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	iset;
	int	start;
	int	len;

	if ((char *)s1 == NULL || (char *)set == NULL)
		return (NULL);
	start = startofstr(s1, set);
	len = (ft_strlen(s1) - 1);
	while (len > start)
	{
		iset = 0;
		while (s1[len] != set[iset] && set[iset] != '\0')
			iset++;
		if (s1[len] == set[iset] && set[iset] != '\0')
			len--;
		else
			break ;
	}
	if (start == 0 && len == 0)
		return (ft_substr(s1, start, (len - start)));
	return (ft_substr(s1, start, (len - start + 1)));
}

/*int	main()
{
	printf("%s\n", ft_strtrim("   xxx   xxx", " x"));
}*/
