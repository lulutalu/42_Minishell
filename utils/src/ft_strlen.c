/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:02:52 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/05 14:32:45 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*int	main()
{
	const char	*str;

	str = "Guit c'est vraiment le plus bo";
	printf("Fonction C = %lu\n", strlen(str));
	printf("Fonction mano = %lu\n", ft_strlen(str));
}*/
