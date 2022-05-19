/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:00:09 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/19 17:51:06 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		idx;
	char	nl;

	nl = '\n';
	idx = 0;
	if (s != NULL)
	{
		while (s[idx] != '\0')
		{
			write(fd, s + idx, 1);
			idx++;
		}
		write(fd, &nl, 1);
	}
}
