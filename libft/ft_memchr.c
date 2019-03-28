/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:32:21 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/01 11:41:51 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		u;
	size_t				i;

	str = s;
	u = c;
	i = 0;
	while (n > i)
	{
		if (str[i] == u)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
