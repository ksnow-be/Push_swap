/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:58:38 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/02 14:05:57 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	sym;

	sym = c;
	while (*s)
	{
		if (*s == sym)
			return ((char *)s);
		s++;
	}
	if (sym == '\0')
		return ((char *)s);
	return (NULL);
}
