/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:02:07 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/19 17:43:16 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
