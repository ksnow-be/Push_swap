/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:15:15 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/08 14:14:21 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strequal_c(char const *s, char c)
{
	while (*s == c && *s)
		s++;
	return ((char *)s);
}

static char	*ft_strnequal_c(char const *s, char c)
{
	while (*s != c && *s)
		s++;
	return ((char *)s);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	char	**ptr;

	i = ft_words_num(s, c);
	str = (char **)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	ptr = str;
	while (i > 0)
	{
		s = ft_strequal_c(s, c);
		*str = ft_str_fill(s, c);
		if (!str)
		{
			ft_del(str, i);
			return (NULL);
		}
		i--;
		str++;
		s = ft_strnequal_c(s, c);
	}
	*str = NULL;
	return (ptr);
}
