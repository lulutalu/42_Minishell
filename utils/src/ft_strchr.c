/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:16:05 by lduboulo          #+#    #+#             */
/*   Updated: 2021/11/23 13:31:39 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *) s + i);
	else
		return (NULL);
}

/*int	main()
{
	char s[] = "tripouille";

	printf("Value Fonction C = %s\n", strchr(s, 't' + 256));
	printf("Value Fonction Mano = %s\n", ft_strchr(s, 't' + 256));
}*/
