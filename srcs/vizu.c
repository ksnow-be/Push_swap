/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 19:33:58 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/24 16:06:41 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		w_detect(t_sta *sta)
{
	int			tmp;
	int			pos;
	int			neg;
	int			tmp_neg;

	neg = sta->size_a - 1;
	pos = sta->size_a - 1;
	tmp = sta->stack_a[pos];
	tmp_neg = sta->stack_a[neg];
	while (pos > -1)
	{
		if (sta->stack_a[pos] > tmp)
			tmp = sta->stack_a[pos];
		pos--;
	}
	while (neg > -1)
	{
		if (sta->stack_a[neg] < tmp_neg)
			tmp_neg = sta->stack_a[neg];
		neg--;
	}
	tmp_neg *= -1;
	if (tmp_neg > tmp)
		tmp = tmp_neg;
	return (tmp);
}

void	draw_rect_a(t_sta *sta, t_vis *vis)
{
	static int	count;
	int			width;
	int			height;
	int			tmp_count;
	int			osy;
	int			ostatokx;
	int			tmp_num;

	if (!count)
		count = sta->amount;
	width = sta->screen_width / w_detect(sta);
	height = sta->screen_height / count;
	ostatokx = 0;
	tmp_count = count - 1;
	if (sta->screen_width - width * sta->size_a)
		ostatokx += sta->screen_width - width * w_detect(sta);
	ostatokx /= 3;
	osy = height - height - height;
	SDL_SetRenderDrawColor(vis->renderer, 94, 196, 205, 1);
	SDL_RenderClear(vis->renderer);
	while (tmp_count > -1)
	{
		SDL_SetRenderDrawColor(vis->renderer, 1, 92, 101, 1);
		osy += height;
		tmp_num = sta->stack_a[tmp_count];
		if (tmp_num < 0)
		{
			SDL_SetRenderDrawColor(vis->renderer, 2, 142, 155, 1);
			tmp_num *= -1;
		}
		else if (tmp_num == 0)
		{
			SDL_SetRenderDrawColor(vis->renderer, 94, 196, 205, 1);
			tmp_num = 1;
		}
		SDL_Rect fillRect = { 0, osy, (ostatokx + width * tmp_num) / 2, height };
		SDL_RenderFillRect(vis->renderer, &fillRect);
		tmp_count--;
	}
	tmp_count = count;
	osy = 0;
	osy -= height;
	while (tmp_count)
	{
		SDL_SetRenderDrawColor(vis->renderer, 1, 92, 101, 1);
		osy += height;
		tmp_num = sta->stack_b[tmp_count - 1];
		if (tmp_num < 0)
		{
			SDL_SetRenderDrawColor(vis->renderer, 2, 142, 155, 1);
			tmp_num *= -1;
		}
		if (tmp_num == 0)
			SDL_SetRenderDrawColor(vis->renderer, 94, 196, 205, 1);
		SDL_Rect fillRect = { sta->screen_width / 2, osy, (ostatokx + width * tmp_num) / 2, height };
		SDL_RenderFillRect(vis->renderer, &fillRect);
		tmp_count--;
	}
	SDL_RenderPresent(vis->renderer);
}

int		scr_h(t_sta *sta)
{
	float	res;

	res = (float)sta->screen_height / (float)sta->size_a;
	res = res - (int)res;
	if (res != 0.0)
	{
		while (res != 0.0)
		{
			sta->screen_height--;
			res = (float)sta->screen_height / (float)sta->size_a;
			res = res - (int)res;
		}
	}
	return (sta->screen_height);
}

void	vizualize(t_sta *sta, t_vis *vis)
{
	int		trig;
	char	*line;

	trig = 1;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		drop("ERROR INIT");
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		drop("ERROR SETHINT");
	vis->window = SDL_CreateWindow("PUSH_SWAP", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sta->screen_width, scr_h(sta), SDL_WINDOW_SHOWN);
	vis->renderer = SDL_CreateRenderer(vis->window, -1, SDL_RENDERER_ACCELERATED);
	while (trig)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				trig = 0;
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_KP_ENTER)
				trig = 0;
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT)
			{
				if (get_next_line(0, &line) == 1)
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
				draw_rect_a(sta, vis);
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT)
			{
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
					draw_rect_a(sta, vis);
				}
			}
		}
	}
	SDL_DestroyRenderer(vis->renderer);
	SDL_DestroyWindow(vis->window);
	SDL_Quit();
}
