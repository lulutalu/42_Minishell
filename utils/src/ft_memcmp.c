/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:21:08 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/22 23:43:34 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
		i++;
	if (i == n)
		return (0);
	else
		return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}

/*int	main()
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	//char s2[] = {0, 0, 127, 0};
	//char s3[] = {0, 0, 42, 0};

	printf("Value Function C = %i\n", memcmp(s, sCpy, 4));
	printf("Value Function Mano = %i\n", ft_memcmp(s, sCpy, 4));
}*/
