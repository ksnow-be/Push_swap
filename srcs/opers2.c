/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:25:19 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/22 18:29:30 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_sta *sta)
{
	int		tmp;
	int		i;

	i = sta->size_a - 1;
	tmp = sta->stack_a[i];
	while (i >= 0)
	{
		if (i != 0)
			sta->stack_a[i] = sta->stack_a[i - 1];
		i--;
	}
	sta->stack_a[i + 1] = tmp;
	sta->count++;
	pisos_man(sta, "ra");
}

void	do_rb(t_sta *sta)
{
	int		tmp;
	int		i;

	i = sta->size_b - 1;
	tmp = sta->stack_b[sta->size_b - 1];
	while (i > 0)
	{
		sta->stack_b[i] = sta->stack_b[i - 1];
		i--;
	}
	sta->stack_b[i] = tmp;
	sta->count++;
	pisos_man(sta, "rb");
}

void	do_rra(t_sta *sta)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = sta->stack_a[i];
	while (i < sta->size_a - 1)
	{
		sta->stack_a[i] = sta->stack_a[i + 1];
		i++;
	}
	sta->stack_a[i] = tmp;
	sta->count++;
	pisos_man(sta, "rra");
}

void	do_rrb(t_sta *sta)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = sta->stack_b[i];
	while (i < sta->size_b - 1)
	{
		sta->stack_b[i] = sta->stack_b[i + 1];
		i++;
	}
	sta->stack_b[i] = tmp;
	sta->count++;
	pisos_man(sta, "rrb");
}

void	do_rrr(t_sta *sta)
{
	do_rra(sta);
	do_rrb(sta);
	pisos_man(sta, "rrr");
}
