/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 22:19:41 by lduboulo          #+#    #+#             */
/*   Updated: 2021/12/30 23:50:34 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		icopy;
	int		istr;

	if (s1 == NULL)
		return (NULL);
	icopy = 0;
	istr = 0;
	copy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (! copy)
		return (NULL);
	while (s1[istr] != '\0')
		copy[icopy++] = s1[istr++];
	copy[icopy] = '\0';
	return (copy);
}
