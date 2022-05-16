/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:38:24 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/12 17:15:07 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dyn_strjoin(char *dynstr, char const *s2)
{
	char	*res;
	int		i1;
	int		i2;
	int		ires;

	ires = 0;
	if (dynstr == NULL || s2 == NULL)
		return (NULL);
	res = ft_calloc((ft_strlen(dynstr) + ft_strlen(s2) + 1), sizeof(char));
	if (! res)
		return (NULL);
	i1 = 0;
	while (dynstr[i1] != '\0')
		res[ires++] = dynstr[i1++];
	i2 = 0;
	while (s2[i2] != '\0')
		res[ires++] = s2[i2++];
	res[ires] = '\0';
	return (res);
}
