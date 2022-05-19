/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:10:12 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/19 17:43:14 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*tmp;
	t_list	*actual;

	actual = *lst;
	tmp = NULL;
	while (actual)
	{
		tmp = actual->next;
		del(actual->content);
		free(actual);
		actual = tmp;
	}
	*lst = NULL;
}
