/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:23:41 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/25 09:56:24 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_solve(t_sta *sta)
{
	while (sta->pis)
	{
		if (sta->pis->pisos)
		{
			ft_putstr(sta->pis->pisos);
			ft_putchar('\n');
		}
		if (sta->pis->next)
			sta->pis = sta->pis->next;
		else
			break ;
	}
}

void	clean_all(t_sta *sta, char **split)
{
	int		z;
	t_pis	*buff;

	z = 0;
	while (sta->pis->prev)
		sta->pis = sta->pis->prev;
	while (sta->pis)
	{
		buff = sta->pis;
		sta->pis = sta->pis->next;
		ft_strdel(&buff->pisos);
		free(buff);
	}
	free(sta->stack_a);
	free(sta->stack_b);
	free(sta);
	while (split[z])
	{
		ft_strdel(&split[z]);
		z++;
	}
	free(split);
}

void	main_begin(char *str)
{
	t_sta	*sta;
	char	**split;

	split = ft_strsplit(str, ' ');
	ft_strdel(&str);
	sta = sta_init(split);
	stack_fill_begin(sta, split);
	sta->mid = pogran(sta);
	while (!sta->finish)
		start_sort(sta);
	drop_rest(sta);
	put_solve(sta);
	clean_all(sta, split);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*lol;
	char	*buff;

	i = 1;
	buff = ft_strnew(0);
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		lol = buff;
		buff = ft_strjoin(buff, argv[i]);
		if (lol)
			ft_strdel(&lol);
		lol = buff;
		buff = ft_strjoin(buff, " ");
		if (lol)
			ft_strdel(&lol);
		i++;
	}
	if (!buff_check(buff))
		drop("Error\n");
	main_begin(buff);
	return (0);
}
