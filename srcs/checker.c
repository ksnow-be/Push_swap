/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:48:56 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/24 15:43:10 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gnl(t_sta *sta)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp(line, "pb"))
			do_pb(sta);
		else if (!ft_strcmp(line, "pa"))
			do_pa(sta);
		else if (!ft_strcmp(line, "sb"))
			do_sb(sta);
		else if (!ft_strcmp(line, "sa"))
			do_sa(sta);
		else if (!ft_strcmp(line, "ra"))
			do_ra(sta);
		else if (!ft_strcmp(line, "rb"))
			do_rb(sta);
		else if (!ft_strcmp(line, "rrb"))
			do_rrb(sta);
		else if (!ft_strcmp(line, "rra"))
			do_rra(sta);
		else if (!ft_strcmp(line, "rrr"))
			do_rrr(sta);
		else
			drop("Error\n");
	}
}

void	clean_checker(t_sta *sta, t_vis *visu, char **split)
{
	t_pis		*bufflol;
	int			z;

	z = 0;
	while (sta->pis->prev)
		sta->pis = sta->pis->prev;
	while (sta->pis)
	{
		bufflol = sta->pis;
		sta->pis = sta->pis->next;
		ft_strdel(&bufflol->pisos);
		free(bufflol);
	}
	free(sta->stack_a);
	free(sta->stack_b);
	free(sta);
	free(visu);
	while (split[z])
	{
		ft_strdel(&split[z]);
		z++;
	}
	free(split);
}

void	checker(char *buff, int vis)
{
	t_sta	*sta;
	char	**split;
	t_vis	*visu;

	split = ft_strsplit(buff, ' ');
	ft_strdel(&buff);
	sta = sta_init(split);
	visu = vis_init();
	stack_fill_begin(sta, split);
	if (vis == 0)
		gnl(sta);
	else if (vis == 1)
		vizualize(sta, visu);
	if (!is_sorted_a(sta) || sta->size_a != sta->amount)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	clean_checker(sta, visu, split);
}

char	*cheker_parser(char *buff, char *ar, int vis)
{
	char	*lol;

	lol = buff;
	buff = ft_strjoin(buff, ar);
	if (lol)
		ft_strdel(&lol);
	lol = buff;
	buff = ft_strjoin(buff, " ");
	if (lol)
		ft_strdel(&lol);
	return (buff);
}

int		main(int argc, char **argv)
{
	int		i;
	int		vis;
	char	*buff;

	vis = 0;
	i = 1;
	buff = ft_strnew(0);
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "-v"))
			buff = cheker_parser(buff, argv[i], vis);
		else
			vis = 1;
		i++;
	}
	if (!buff_check(buff))
		drop("Error\n");
	checker(buff, vis);
	return (0);
}
