/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:52:36 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/05 19:46:55 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (c);
	else
		return (-1);
}

/*int main()
{
	char	c;

	c = ' ';
	printf("Resultat Fonction C = %i\n", isalnum(c));
	printf("Resultat Fonction mano = %i\n", ft_isalnum(c));
}*/
