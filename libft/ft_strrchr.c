/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:19:33 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/02 14:07:19 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	sym;
	int		i;

	sym = c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == sym)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
