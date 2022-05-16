/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:03:12 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/28 14:29:29 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	size_t	idx;

	idx = 0;
	if (s != NULL)
	{
		while (idx < ft_strlen(s))
		{
			f(idx, s + idx);
			idx++;
		}
	}
}
