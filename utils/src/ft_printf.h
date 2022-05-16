/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:06:52 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/27 19:29:47 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include "libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct printf_list
{
	int		count;
	int		i;
	va_list	arg;
	char	*str;
	int		nbvar;
	char	*param;
	int		iparam;
}				t_printf;

void	core_process(t_printf *ptr, const char *input);
void	hexa_process(t_printf *ptr, int flag);
void	string_process(t_printf *ptr);
void	pointer_address_process(t_printf *ptr);
void	variable_counter(t_printf *ptr, const char *input);
void	struct_init(t_printf *ptr);
void	if_forest(const char *input, t_printf *ptr);
int		ft_printf(const char *input, ...);

#endif
