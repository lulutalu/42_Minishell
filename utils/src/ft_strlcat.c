/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:30:05 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/24 20:03:29 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idxdst;
	size_t	idxsrc;
	size_t	i;

	i = ft_strlen(src) + ft_strlen(dst);
	idxsrc = 0;
	idxdst = 0;
	while (dst[idxdst] != '\0' && dstsize > idxdst)
		idxdst++;
	if (dstsize == idxdst)
		return (dstsize + ft_strlen(src));
	if ((dstsize - 1) == idxdst)
		return (i);
	while (src[idxsrc] != '\0' && (dstsize - 1) > idxdst)
		dst[idxdst++] = src[idxsrc++];
	dst[idxdst] = '\0';
	if (src[idxsrc] == '\0')
		return (idxdst);
	else
		return (i);
}

/*int main()
{
	char	dst[40] = "Test";

    printf("Function res = %lu\n", strlcat(dst, "aueeee", 14));
	printf("String = %s\n", dst);
}*/
