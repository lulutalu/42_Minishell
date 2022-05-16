/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:55:02 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/27 19:28:03 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexa_process(t_printf *ptr, int flag)
{
	char	*base_up;
	char	*base_low;

	base_up = "0123456789ABCDEF";
	base_low = "0123456789abcdef";
	if (flag == 0)
	{
		ft_itoa_base(&ptr->str, (unsigned int)va_arg(ptr->arg, int), base_low);
		ptr->count += ft_putstr_fd_count(ptr->str, 1);
		free(ptr->str);
	}
	else
	{
		ft_itoa_base(&ptr->str, (unsigned int)va_arg(ptr->arg, int), base_up);
		ptr->count += ft_putstr_fd_count(ptr->str, 1);
		free(ptr->str);
	}
}
