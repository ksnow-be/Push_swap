/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:02:46 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/08 16:45:13 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	const char	*hay;
	const char	*need;
	size_t		i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && n > 0)
	{
		hay = haystack;
		need = needle;
		while (*hay == *need && *need && i++ < n)
		{
			hay++;
			need++;
		}
		i = 0;
		if (!*need)
			return ((char *)haystack);
		n--;
		haystack++;
	}
	return (NULL);
}
