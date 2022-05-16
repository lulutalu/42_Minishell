/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:10:36 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/07 19:33:59 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//alst : Adresse du pointeur vers le premier element de la liste
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (! alst || ! new)
		return ;
	new->next = *alst;
	*alst = new;
}
