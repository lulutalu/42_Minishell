/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:09:19 by lduboulo          #+#    #+#             */
/*   Updated: 2021/12/17 13:57:57 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	t_printf	*ptr;
	t_printf	a;

	ptr = &a;
	va_start(ptr->arg, input);
	struct_init(ptr);
	variable_counter(ptr, input);
	ptr->i = 0;
	core_process(ptr, input);
	while (input[ptr->i])
		ptr->count += ft_putchar_fd_count(input[ptr->i++], 1);
	return (ptr->count);
}
