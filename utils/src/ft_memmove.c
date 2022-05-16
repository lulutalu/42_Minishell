/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:52:39 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/22 22:06:29 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			*((char *)dst + (len - 1)) = *((char *)src + (len - 1));
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	return (dst);
}

/*int main()
{
	char	dst[] = "A";
	char	src[] = "A";

	printf("Before Function = %s\n", dst);
	ft_memmove(dst, src, 1);
	printf("After Function = %s\n", dst);
}*/
