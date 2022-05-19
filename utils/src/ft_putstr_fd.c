/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:39:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/19 17:51:21 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	idx;

	idx = 0;
	if (s != NULL)
	{
		while (s[idx] != '\0')
		{
			write(fd, s + idx, 1);
			idx++;
		}
	}
}
