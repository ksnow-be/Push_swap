/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:13:55 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/14 12:07:01 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest_str;
	char	*src_str;
	int		i;

	if (dst == src)
		return (dst);
	dest_str = (char *)dst;
	src_str = (char *)src;
	i = 0;
	while (n-- > 0)
	{
		dest_str[i] = src_str[i];
		i++;
	}
	return (dst);
}
