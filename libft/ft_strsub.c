/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:05:41 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/07 18:38:38 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str || !s)
		return (NULL);
	while (len > 0 && *(s + start))
	{
		*str++ = *(s + start++);
		len--;
		i++;
	}
	*str = '\0';
	return (str - i);
}
