/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:03:28 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/15 17:28:32 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
	}
	else
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		while (src[i])
			i++;
	}
	return (i);
}

/*int	main()
{
	char	dst[] = "Destination";
	char	src[] = "Je dois etre copie";
	size_t	dstsize = 13;

	printf("Before function = %s\n", dst);
	printf("Fonction C = %lu\n", ft_strlcpy(dst, src, dstsize));
	printf("after Function = %s\n", dst);
}*/
