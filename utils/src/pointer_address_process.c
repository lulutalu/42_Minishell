/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_address_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:38:41 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/27 19:28:30 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer_address_process(t_printf *ptr)
{
	char	*base;

	base = "0123456789abcdef";
	ptr->count += ft_putstr_fd_count("0x", 1);
	ft_itoa_base(&ptr->str, (unsigned long)va_arg(ptr->arg, void *), base);
	ptr->count += ft_putstr_fd_count(ptr->str, 1);
	free(ptr->str);
}
