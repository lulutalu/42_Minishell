/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_alloc_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:38:54 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/23 23:01:00 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_mem_alloc_check(void *ptr)
{
	if (ptr == NULL)
	{
		free(ptr);
		ft_putendl_fd("Error, dynamic allocation failed", 2);
		exit(EXIT_FAILURE);
	}
}
