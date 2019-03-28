/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:10:02 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/24 16:09:25 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "SDL.h"

typedef struct		s_pis
{
	char			*pisos;
	struct s_pis	*next;
	struct s_pis	*prev;
}					t_pis;

typedef struct		s_sta
{
	int				size_a;
	int				*stack_a;
	int				size_b;
	int				*stack_b;
	int				mid;
	int				vizu;
	int				screen_width;
	int				screen_height;
	int				start_ready;
	int				mid_trig;
	int				count;
	int				amount;
	int				sleep;
	int				finish;
	int				max_line;
	int				min_line;
	int				mid_line;
	int				left;
	int				down;
	int				p_amount;
	int				tmp_p_amount;
	int				tmp;
	t_pis			*pis;
}					t_sta;

typedef struct		s_vis
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_vis;

void				do_sa(t_sta *sta);
void				do_sb(t_sta *sta);
void				do_ss(t_sta *sta);

void				do_pb(t_sta *sta);
void				do_pa(t_sta *sta);
void				do_ra(t_sta *sta);
void				do_rb(t_sta *sta);
void				do_rr(t_sta *sta);
void				do_rra(t_sta *sta);
void				do_rrb(t_sta *sta);
void				do_rrr(t_sta *sta);

void				stack_fill_begin(t_sta *sta, char **split);
t_sta				*sta_init(char **split);

t_vis				*vis_init(void);
void				put_solve(t_sta *sta);
void				drop(char *str);
int					check_on_num(char *str);
int					buff_check(char *buff);
int					check_double(char **split);
void				main_begin(char *buff);

void				vizualize(t_sta *sta, t_vis *vis);
void				draw_rect_a(t_sta *sta, t_vis *vis);
int					w_detect(t_sta *sta);
int					scr_h(t_sta *sta);

void				help_mid_sort(t_sta *sta);
void				mid_detect_min_max(t_sta *sta);
void				detect_mid_left_mm(t_sta *sta, int count);
void				detect_max_and_amount(t_sta *sta);
void				small_sort(t_sta *sta);
void				pisos_man(t_sta *sta, char *str);
void				middle_sort(t_sta *sta);
void				start_sort(t_sta *sta);
int					pogran(t_sta *sta);
int					check_status(t_sta *sta);
int					is_sorted_a(t_sta *sta);
int					have_bigger_simple(t_sta *sta);
int					check_amo_need(t_sta *sta);
void				perebroska(t_sta *sta);
void				mid_perebroska(t_sta *sta);
void				middle_left(t_sta *sta, int count);
int					is_more_need(t_sta *sta, int middle);
int					add_more_left(t_sta *sta, int middle);
void				drop_rest(t_sta *sta);
void				del_list(t_pis *tmp1, t_pis *tmp2);
void				checker_prep(t_sta *sta);
void				checker(char *buff, int vis);
void				clean_checker(t_sta *sta, t_vis *visu, char **split);

void				small_mid_sort(t_sta *sta);
void				pre_small_sort(t_sta *sta);
void				small_pere(t_sta *sta);
void				small_pa(t_sta *sta);

int					sb_check(t_sta *sta);
int					pa_sa_check(t_sta *sta);
int					sa_check(t_sta *sta);
int					mid_sort_check(t_sta *sta);
int					sany_cheburek(int a);

#endif
