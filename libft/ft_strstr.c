/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:50:26 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/08 16:09:57 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*hay;
	const char	*need;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		hay = haystack;
		need = needle;
		while (*hay == *need && *need)
		{
			hay++;
			need++;
		}
		if (!*need)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
