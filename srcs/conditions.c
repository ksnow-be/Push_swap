/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:50:19 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/24 15:50:08 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sb_check(t_sta *sta)
{
	if (sta->size_b > 1 &&
			sta->stack_b[sta->size_b - 1] < sta->stack_b[sta->size_b - 2])
		return (1);
	return (0);
}

int		pa_sa_check(t_sta *sta)
{
	if (sany_cheburek(sta->size_b - 1) == 0
			&& sany_cheburek(sta->size_b - 2) == 0
			&& sta->stack_b[sta->size_b - 1] > sta->stack_b[sta->size_b - 2]
			&& !have_bigger_simple(sta))
		return (1);
	return (0);
}

int		sa_check(t_sta *sta)
{
	if (sany_cheburek(sta->size_b - 1) == 0
			&& sany_cheburek(sta->size_b - 2) == 0
			&& sta->stack_a[sta->size_a - 1] > sta->stack_a[sta->size_a - 2])
		return (1);
	return (0);
}

int		mid_sort_check(t_sta *sta)
{
	if (sta->size_b > 1
			&& sta->stack_b[sta->size_b - 1] > sta->stack_b[sta->size_b - 2]
			&& have_bigger_simple(sta))
		return (1);
	return (0);
}
