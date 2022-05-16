/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:58:47 by lduboulo          #+#    #+#             */
/*   Updated: 2021/12/03 14:38:59 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Itoa base only works for base different than 10
// For base 10 use the regular Itoa

int	nbrlen(unsigned long n, unsigned int tbase)
{
	int	len;

	len = 0;
	if (n < tbase)
		len = 0;
	else
	{
		while (n >= tbase)
		{
			n /= tbase;
			len++;
		}
	}
	return (len);
}

void	*fillerstr(char **res, unsigned long n, int tbase)
{
	int		ires;

	ires = nbrlen(n, tbase);
	while (ires >= 0)
	{
		(*res)[ires] = '0' + n % tbase;
		n /= tbase;
		ires--;
	}
	return (NULL);
}

void	*check_base(char **res, char const *base)
{
	int	ires;
	int	ibase;

	ires = 0;
	while ((*res)[ires])
	{
		if ((*res)[ires] <= '9')
			ires++;
		else
		{
			ibase = ((*res)[ires] - '9') + 9;
			(*res)[ires] = base[ibase];
			ires++;
		}
	}
	return (NULL);
}

void	*ft_itoa_base(char **res, unsigned long n, char const *base)
{
	int		tbase;

	tbase = ft_strlen(base);
	*res = ft_calloc((nbrlen(n, tbase) + 2), sizeof(char));
	if (*res == NULL)
		return (NULL);
	fillerstr(res, n, tbase);
	check_base(res, base);
	return (NULL);
}

/*int	main()
{
	char	*str;

	printf("%s\n", ft_itoa_base(&str, 0, "0123456789abcdef"));
}*/
