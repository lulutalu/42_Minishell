/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:50:49 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/15 16:28:33 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src || n == 0)
		return (dst);
	while (i < n)
	{
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	return (dst);
}

/*int	main()
{
	size_t	n = 26;
	char	dst[] = "Ceci est une destination";
	char	src[] = "Ceci est une source";

	printf("Before Function = %s\n", dst);
	memcpy(dst + 5, src, n);
	printf("after Function = %s\n", dst);
}*/
