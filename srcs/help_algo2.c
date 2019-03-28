/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:32:43 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/20 18:04:35 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		detect_min_max(t_sta *sta)
{
	int	i;

	i = sta->size_b - 1;
	sta->min_line = sta->stack_b[i];
	sta->max_line = sta->stack_b[i];
	while (i != -1)
	{
		if (sta->stack_b[i] > sta->max_line)
			sta->max_line = sta->stack_b[i];
		if (sta->stack_b[i] < sta->min_line)
			sta->min_line = sta->stack_b[i];
		i--;
	}
	sta->mid_line = sta->min_line + (sta->max_line - sta->min_line) / 2;
}

void		mid_perebroska(t_sta *sta)
{
	int	i;

	detect_min_max(sta);
	i = sta->size_b - 1;
	while (i)
	{
		if (sta->stack_b[sta->size_b - 1] >= sta->mid_line)
		{
			do_pa(sta);
			sta->left++;
		}
		else
			do_rb(sta);
		i--;
	}
	while (sta->left)
	{
		do_pb(sta);
		sta->left--;
	}
	sta->mid_trig = 1;
}

void		mid_detect_min_max(t_sta *sta)
{
	int	i;

	i = sta->size_b - 1;
	sta->max_line = sta->stack_b[i];
	while (i != -1)
	{
		if (sta->stack_b[i] > sta->max_line)
			sta->max_line = sta->stack_b[i];
		i--;
	}
	i = sta->size_b - 1;
	while (i != -1)
	{
		if (sta->stack_b[i] == sta->max_line)
			break ;
		i--;
		sta->p_amount++;
	}
	sta->tmp_p_amount = sta->p_amount;
}

int			check_status(t_sta *sta)
{
	int	cur;

	cur = sta->size_a - 1;
	while (cur != -1)
	{
		if (sta->stack_a[cur] < sta->mid)
			return (1);
		cur--;
	}
	return (0);
}

int			have_bigger_simple(t_sta *sta)
{
	int		i;
	int		tmp;

	tmp = sta->stack_b[sta->size_b - 1];
	i = sta->size_b - 1;
	while (i != -1)
	{
		if (sta->stack_b[i] > tmp)
			return (1);
		i--;
	}
	return (0);
}
