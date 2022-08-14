/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:41:07 by lduboulo          #+#    #+#             */
/*   Updated: 2022/08/14 16:42:01 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	isub;
	size_t	sizeof_s;

	sizeof_s = ft_strlen(s);
	isub = 0;
	if (s == NULL)
		return (NULL);
	if (start > sizeof_s)
		return (ft_strdup(""));
	if ((sizeof_s - start) < len)
		substr = malloc((sizeof_s - start + 1) * sizeof(char));
	else
		substr = malloc((len + 1) * sizeof(char));
	if (! substr)
		return (NULL);
	while (isub < len && s[start] != '\0')
		substr[isub++] = s[start++];
	substr[isub] = '\0';
	return (substr);
}

/*int	main()
{
	printf("%s\n", ft_substr(NULL, 0, 12));
}*/
