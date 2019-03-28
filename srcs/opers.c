/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:41:01 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/24 15:44:17 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_sta *sta)
{
	int	tmp;

	if (sta->size_a < 2)
		return ;
	tmp = sta->stack_a[sta->size_a - 1];
	sta->stack_a[sta->size_a - 1] = sta->stack_a[sta->size_a - 2];
	sta->stack_a[sta->size_a - 2] = tmp;
	sta->count++;
	pisos_man(sta, "sa");
}

void	do_sb(t_sta *sta)
{
	int		tmp;

	if (sta->size_b < 2)
		return ;
	tmp = sta->stack_b[sta->size_b - 1];
	sta->stack_b[sta->size_b - 1] = sta->stack_b[sta->size_b - 2];
	sta->stack_b[sta->size_b - 2] = tmp;
	sta->count++;
	pisos_man(sta, "sb");
}

void	do_pb(t_sta *sta)
{
	if (sta->size_a == 0)
		return ;
	sta->stack_b[sta->size_b] = sta->stack_a[sta->size_a - 1];
	sta->stack_a[sta->size_a - 1] = 0;
	sta->size_a--;
	sta->size_b++;
	sta->count++;
	pisos_man(sta, "pb");
}

void	do_pa(t_sta *sta)
{
	int		tmp;

	if (!sta->size_b)
		return ;
	sta->size_a++;
	sta->stack_a[sta->size_a - 1] = sta->stack_b[sta->size_b - 1];
	sta->stack_b[sta->size_b - 1] = 0;
	sta->size_b--;
	sta->count++;
	pisos_man(sta, "pa");
}
