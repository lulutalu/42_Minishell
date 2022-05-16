/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:41:15 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/27 21:00:29 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*res;
	size_t	ires;

	if (s == NULL)
		return (NULL);
	ires = 0;
	res = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (res == NULL)
		return (NULL);
	while (ires < ft_strlen(s))
	{
		res[ires] = f(ires, s[ires]);
		ires++;
	}
	return (res);
}
