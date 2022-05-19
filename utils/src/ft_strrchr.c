/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:50:46 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/19 17:57:07 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] != (char)c && i > 0)
		i--;
	if (s[i] == (char)c)
		return ((char *) s + i);
	else
		return (NULL);
}

/*int	main()
{
	const char	s[] = "Guit le boG";
	char	c = 'a';

	printf("Value Fonction C = %s\n", strrchr(s, c));
	printf("Value Fonction mano = %s\n", ft_strrchr(s, c));
}*/
