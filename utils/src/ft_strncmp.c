/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:07:14 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/25 16:23:05 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (n > 0 && s1[idx] != '\0' && s2[idx] != '\0')
	{
		if (s1[idx] != s2[idx])
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		idx++;
		n--;
	}
	if ((s1[idx] == '\0' || s2[idx] == '\0') && n > 0)
		return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
	return (0);
}

/*int	main()
{
	char	*big = "abcdef";
	char	*little = "abcdefghijklmnop";
	size_t	size = 6;

	printf("Fonction C = %d\n", strncmp(big, little, size));
	printf("Fonction Mano = %d\n", ft_strncmp(big, little, size));
}*/
