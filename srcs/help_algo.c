/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:19:00 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/20 18:04:04 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exec_perebroska(t_sta *sta)
{
	int	i;

	while (sta->tmp_p_amount != -1)
	{
		i = sta->size_b - 1;
		if (sta->stack_b[i] > sta->mid_line)
		{
			do_pa(sta);
			sta->left++;
		}
		else if (sta->stack_b[i] <= sta->mid_line)
		{
			do_rb(sta);
			sta->down++;
		}
		sta->tmp_p_amount--;
	}
	while (sta->down)
	{
		do_rrb(sta);
		sta->down--;
	}
	if (sta->left)
		middle_left(sta, sta->left);
	sta->left = 0;
}

void		perebroska(t_sta *sta)
{
	int	i;

	mid_detect_min_max(sta);
	i = sta->size_b - 1;
	sta->min_line = sta->stack_b[i];
	while (sta->p_amount)
	{
		if (sta->stack_b[i] < sta->min_line)
			sta->min_line = sta->stack_b[i];
		i--;
		sta->p_amount--;
	}
	sta->mid_line = (sta->max_line - sta->min_line) / 2 + sta->min_line;
	exec_perebroska(sta);
}

void		detect_mid_left_mm(t_sta *sta, int count)
{
	int	i;

	i = sta->size_a - 1;
	sta->min_line = sta->stack_a[i];
	sta->max_line = sta->stack_a[i];
	sta->tmp = count;
	while (sta->tmp)
	{
		if (sta->stack_a[i] > sta->max_line)
			sta->max_line = sta->stack_a[i];
		if (sta->stack_a[i] < sta->min_line)
			sta->min_line = sta->stack_a[i];
		sta->tmp--;
		i--;
	}
	sta->tmp = count;
	sta->mid_line = (sta->min_line + (sta->max_line - sta->min_line) / 2);
}

void		middle_left(t_sta *sta, int count)
{
	detect_mid_left_mm(sta, count);
	while (sta->tmp)
	{
		if (sta->stack_a[sta->size_a - 1] >= sta->mid_line)
		{
			do_ra(sta);
			sta->down++;
		}
		else if (sta->stack_a[sta->size_a - 1] < sta->mid_line)
			do_pb(sta);
		sta->tmp--;
	}
	while (sta->down)
	{
		do_rra(sta);
		do_pb(sta);
		sta->down--;
	}
}

int			check_amo_need(t_sta *sta)
{
	int	max;
	int	i;
	int	res;

	res = 0;
	i = sta->size_b - 1;
	max = sta->stack_b[i];
	while (i != -1)
	{
		if (sta->stack_b[i] > max)
			max = sta->stack_b[i];
		i--;
	}
	i = sta->size_b - 1;
	while (i != -1)
	{
		if (sta->stack_b[i] == max)
			return (res);
		i--;
		res++;
	}
	return (0);
}
