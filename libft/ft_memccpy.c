/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:11:13 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/08 17:52:19 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	unsigned char		sym;
	size_t				i;

	i = 0;
	dest_ptr = dest;
	src_ptr = src;
	sym = c;
	while (n > i)
	{
		*(dest_ptr + i) = *(src_ptr + i);
		if (*(src_ptr + i) == sym)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
