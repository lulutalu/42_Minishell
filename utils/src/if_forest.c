/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_forest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:15:41 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/27 19:28:17 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_forest(const char *input, t_printf *ptr)
{
	unsigned int	res;

	if (input[ptr->i + 1] == 'c')
		ptr->count += ft_putchar_fd_count(va_arg(ptr->arg, int), 1);
	if (input[ptr->i + 1] == 's')
		string_process(ptr);
	if (input[ptr->i + 1] == 'p')
		pointer_address_process(ptr);
	if (input[ptr->i + 1] == 'd')
		ft_putnbr_fd_count(va_arg(ptr->arg, int), 1, &ptr->count);
	if (input[ptr->i + 1] == 'i')
		ft_putnbr_fd_count(va_arg(ptr->arg, int), 1, &ptr->count);
	if (input[ptr->i + 1] == 'u')
	{
		res = va_arg(ptr->arg, int);
		ft_putnbr_fd_count(res, 1, &ptr->count);
	}
	if (input[ptr->i + 1] == 'x')
		hexa_process(ptr, 0);
	if (input[ptr->i + 1] == 'X')
		hexa_process(ptr, 1);
	if (input[ptr->i + 1] == '%')
		ptr->count += ft_putchar_fd_count('%', 1);
}
