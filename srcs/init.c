/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:26:32 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/24 15:43:47 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_fill_begin(t_sta *sta, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		sta->stack_a[sta->size_a - i - 1] = ft_atoi(split[i]);
		sta->stack_b[sta->size_a - i - 1] = 0;
		i++;
	}
	sta->amount = i;
}

t_vis	*vis_init(void)
{
	t_vis	*res;

	res = (t_vis*)malloc(sizeof(t_vis));
	res->window = NULL;
	res->renderer = NULL;
	return (res);
}

void	fill_sta(t_sta *res, int i)
{
	res->pis->next = NULL;
	res->pis->prev = NULL;
	res->pis->pisos = NULL;
	res->size_a = i;
	res->size_b = 0;
	res->screen_width = 1800;
	res->screen_height = 1300;
	res->mid = 0;
	res->start_ready = 0;
	res->count = 0;
	res->amount = 0;
	res->mid_trig = 0;
	res->sleep = 100;
	res->finish = 0;
	res->vizu = 0;
	res->max_line = 0;
	res->min_line = 0;
	res->left = 0;
	res->down = 0;
	res->p_amount = 0;
	res->tmp_p_amount = 0;
	res->tmp = 0;
}

t_sta	*sta_init(char **split)
{
	t_sta	*res;
	int		i;

	i = 0;
	while (split[i])
		i++;
	res = (t_sta*)malloc(sizeof(t_sta));
	if (!res)
		drop("FIRE");
	res->pis = (t_pis*)malloc(sizeof(t_pis));
	res->stack_a = (int*)malloc(sizeof(int) * i);
	res->stack_b = (int*)malloc(sizeof(int) * i);
	if (!res || !res->stack_a || !res->stack_b || !res->pis)
	{
		ft_putstr("ERROR INIT STACKS");
		exit(1);
	}
	fill_sta(res, i);
	return (res);
}
