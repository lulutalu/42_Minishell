/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:58:43 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/27 19:28:53 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	struct_init(t_printf *ptr)
{
	ptr->i = 0;
	ptr->count = 0;
	ptr->nbvar = 0;
	ptr->param = "cspdiuxX%";
}
