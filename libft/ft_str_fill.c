/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:09:40 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/08 14:11:16 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_fill(char const *s, char c)
{
	int			i;
	char		*str;
	const char	*ptr;
	char		*res;

	i = 0;
	ptr = s;
	while (*ptr++ != c && *ptr)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	res = str;
	while (*s != c && *s)
		*str++ = *s++;
	*str = 0;
	return (res);
}
