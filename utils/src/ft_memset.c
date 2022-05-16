/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:38:33 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/15 16:28:52 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int	ib;

	ib = 0;
	while (len-- > 0)
		((char *)b)[ib++] = c;
	return (b);
}

/*int main()
{
	char	b[] = "Ceci est un test";
	int	c;
	unsigned long	len;

	c = 43;
	len = 1;
	printf("Fonction C = %s\n", memset(b, c, len));
	printf("Fonction Mano = %s\n", ft_memset(b, c, len));
}*/
