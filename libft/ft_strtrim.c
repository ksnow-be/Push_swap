/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:09:12 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/08 13:43:25 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_whitespaces(char const *s, int a)
{
	int		i;

	i = a;
	if (a == 0)
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
	}
	else
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	char	*ptr;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	k = 0;
	i = ft_strlen(s) - 1;
	k = ft_skip_whitespaces(s, k);
	if (!s[k])
	{
		str = ft_strnew(1);
		*str = s[k];
		return (str);
	}
	i = ft_skip_whitespaces(s, i);
	str = ft_strnew(i - k + 1);
	if (!str)
		return (NULL);
	ptr = str;
	while (k <= i)
		*str++ = s[k++];
	*str = '\0';
	return (ptr);
}
