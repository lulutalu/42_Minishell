/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:07:03 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/11 12:29:40 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (c);
	else
		return (0);
}

/*int main()
{
	char	c;

	c = 'Z';
	printf("Fonction C, resultat = %i\n", isalpha(c));
	printf("Fontion mano, resultat = %i\n", ft_isalpha(c));
}*/
