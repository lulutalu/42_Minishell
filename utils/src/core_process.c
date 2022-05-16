/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:03:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/27 19:27:46 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	core_process(t_printf *ptr, const char *input)
{
	while (ptr->nbvar > 0)
	{
		if (input[ptr->i] == '%')
		{
			if_forest(input, ptr);
			ptr->i += 2;
			ptr->nbvar--;
			if (ptr->nbvar == 0)
				break ;
		}
		else
		{
			ptr->count += ft_putchar_fd_count(input[ptr->i], 1);
			ptr->i++;
		}
	}
}
