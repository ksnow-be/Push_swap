/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:06:55 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/25 08:47:40 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	drop(char *str)
{
	ft_putstr(str);
	exit(1);
}

int		check_on_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
				|| (str[i] == '+' || str[i] == '-'))
			i++;
		else
			return (0);
	}
	return (1);
}

int		check_double(char **split)
{
	int	i;
	int	k;

	i = 0;
	while (split[i])
	{
		k = i + 1;
		if (!split[k])
			break ;
		while (split[k])
		{
			if (ft_atoi(split[k]) == ft_atoi(split[i]))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

void	clean_split(char **split)
{
	int	z;

	z = 0;
	while (split[z])
	{
		ft_strdel(&split[z]);
		z++;
	}
	free(split);
}

int		buff_check(char *buff)
{
	char		**split;
	int			i;
	int			k;

	if (!buff)
		return (0);
	i = 0;
	split = ft_strsplit(buff, ' ');
	while (split[i])
	{
		if (ft_atoi(split[i]) == 0)
			if (!check_on_num(split[i]))
				return (0);
		if (ft_strlen(split[i]) >= 10)
			return (0);
		i++;
	}
	if (!check_double(split) || i == 0)
		return (0);
	clean_split(split);
	return (1);
}
