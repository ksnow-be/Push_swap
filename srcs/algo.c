/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:07:12 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/24 15:31:54 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sorted_a(t_sta *sta)
{
	int	i;

	i = sta->size_a - 1;
	if (!sta->size_a)
		return (0);
	while (i >= 0)
	{
		if (i != 0 && (sta->stack_a[i] > sta->stack_a[i - 1]))
			return (0);
		i--;
	}
	return (1);
}

void		help_mid_sort(t_sta *sta)
{
	int	i;

	i = 0;
	if (check_amo_need(sta) >= (sta->amount / 30))
		perebroska(sta);
	else if (check_amo_need(sta) < (sta->amount / 30))
	{
		while (have_bigger_simple(sta))
		{
			do_rb(sta);
			i++;
		}
		do_pa(sta);
		while (i)
		{
			do_rrb(sta);
			i--;
		}
	}
}

void		middle_sort(t_sta *sta)
{
	if (sta->size_a > sta->size_b && sta->mid_trig == 0)
		mid_perebroska(sta);
	if (sb_check(sta))
		do_sb(sta);
	else if (pa_sa_check(sta))
	{
		do_pa(sta);
		if (sa_check(sta))
			do_sa(sta);
	}
	else if (mid_sort_check(sta))
		help_mid_sort(sta);
	else if (sta->size_b > 0 && sta->size_a > 0
			&& sta->stack_b[sta->size_b - 1] > sta->stack_a[sta->size_a - 1])
	{
		do_pa(sta);
		if (sta->size_a > 1
			&& sta->stack_a[sta->size_a - 1] > sta->stack_a[sta->size_a - 2])
			do_sa(sta);
	}
	else if (is_sorted_a(sta) && sta->size_b == 1)
		do_pa(sta);
	if (sta->start_ready && !sta->size_b)
		sta->finish = 1;
}

void		small_sort(t_sta *sta)
{
	if (is_sorted_a(sta))
	{
		sta->finish = 1;
		return ;
	}
	if (sta->size_a > 1
			&& sta->stack_a[sta->size_a - 1] > sta->stack_a[sta->size_a - 2])
	{
		if (sta->stack_a[sta->size_a - 1] > sta->stack_a[0])
			do_ra(sta);
		else
			do_sa(sta);
	}
	else if (sta->stack_a[sta->size_a - 1] < sta->stack_a[sta->size_a - 2])
	{
		if (sta->stack_a[sta->size_a - 1] > sta->stack_a[0])
			do_rra(sta);
		else
		{
			do_rra(sta);
			do_sa(sta);
		}
	}
}

void		start_sort(t_sta *sta)
{
	if (is_sorted_a(sta) && !sta->size_b)
	{
		sta->finish = 1;
		return ;
	}
	if (sta->amount <= 5)
		pre_small_sort(sta);
	else
	{
		if (is_sorted_a(sta))
		{
			sta->start_ready = 1;
			middle_sort(sta);
		}
		else if (sta->start_ready == 0)
		{
			if (sta->stack_a[sta->size_a - 1] >= sta->mid)
				do_ra(sta);
			else
				do_pb(sta);
			if (!check_status(sta))
				sta->mid = pogran(sta);
		}
	}
}
