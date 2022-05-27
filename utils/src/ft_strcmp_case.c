/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:02:17 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/27 17:34:23 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_strcmp_case(const char *s1, const char *s2)
{
	int	idx;

	if (!s1)
		return (-1);
	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		if (s1[idx] != s2[idx])
		{
			if (!(s1[idx] - s2[idx] == 32 || s2[idx] - s1[idx] == 32))
				return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		}
		idx++;
	}
	if (s1[idx] == '\0' || s2[idx] == '\0')
		return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
	return (0);
}
