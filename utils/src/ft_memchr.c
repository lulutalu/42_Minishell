/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:39:39 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/24 16:52:45 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- > 0)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}

/*int	main()
{
	char	str[] = "Test";
	char	c = 's';
	size_t	n = 3;

	printf("Res function c = %s\n", memchr(str, c, n));
	printf("Res function mano = %s\n", ft_memchr(str, c, n));
}*/
