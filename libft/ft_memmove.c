/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:45:38 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/01 14:30:11 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	dst_ptr = dst;
	src_ptr = src;
	if (dst_ptr > src_ptr)
	{
		while (len > 0)
		{
			*(dst_ptr + len - 1) = *(src_ptr + len - 1);
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*dst_ptr++ = *src_ptr++;
			len--;
		}
	}
	return (dst);
}
