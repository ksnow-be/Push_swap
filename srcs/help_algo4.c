/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_algo4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:25:38 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/24 15:38:11 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sany_cheburek(int a)
{
	if (a >= 0)
		return (0);
	return (1);
}

void		small_pere(t_sta *sta)
{
	int	i;

	i = sta->size_a - 1;
	while (i != -1)
	{
		if (sta->stack_a[sta->size_a - 1] >= sta->mid)
			do_ra(sta);
		else if (sta->stack_a[sta->size_a - 1] < sta->mid)
			do_pb(sta);
		i--;
	}
	sta->start_ready = 1;
}

void		small_pa(t_sta *sta)
{
	int	tmp;

	tmp = sta->size_b;
	while (tmp >= 0)
	{
		do_pa(sta);
		tmp--;
	}
}

void		small_mid_sort(t_sta *sta)
{
	if (is_sorted_a(sta) && !sta->size_b)
	{
		sta->finish = 1;
		return ;
	}
	if (!sta->start_ready)
		small_pere(sta);
	if (sta->size_b >= 2
			&& sta->stack_b[sta->size_b - 1] < sta->stack_b[sta->size_b - 2])
		do_sb(sta);
	else if (sta->size_a >= 2
			&& sta->stack_a[sta->size_a - 1] > sta->stack_a[sta->size_a - 2])
		do_sa(sta);
	else if (sta->size_a >= 2
			&& sta->stack_a[sta->size_a - 1] < sta->stack_a[sta->size_a - 2])
		do_rra(sta);
	if (is_sorted_a(sta) && sta->size_b)
		small_pa(sta);
}

void		pre_small_sort(t_sta *sta)
{
	if (sta->amount <= 3)
		small_sort(sta);
	else
	{
		small_mid_sort(sta);
		sta->mid = pogran(sta);
	}
}
