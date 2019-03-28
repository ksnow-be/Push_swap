/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_algo3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:39:33 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/24 15:39:39 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			pogran(t_sta *sta)
{
	int		lower;
	int		count;
	int		higher;

	count = sta->size_a - 1;
	lower = sta->stack_a[count];
	higher = sta->stack_a[count];
	while (count != -1)
	{
		if (sta->stack_a[count] < lower)
			lower = sta->stack_a[count];
		if (sta->stack_a[count] > higher)
			higher = sta->stack_a[count];
		count--;
	}
	return (lower + ((higher - lower) / 2));
}

void		pisos_man(t_sta *sta, char *str)
{
	t_pis	*tmp;
	t_pis	*tmp_st;

	tmp_st = sta->pis;
	while (tmp_st->next)
		tmp_st = tmp_st->next;
	if (!tmp_st->pisos)
	{
		tmp_st->pisos = ft_strdup(str);
		if (!tmp_st->pisos)
			drop("ERROR TMP_ST PIS");
	}
	else
	{
		tmp = (t_pis*)malloc(sizeof(t_pis));
		if (!tmp)
			drop("ERROR MAL PIS");
		tmp->pisos = ft_strdup(str);
		if (!tmp->pisos)
			drop("ERROR PISOS");
		tmp->prev = tmp_st;
		tmp->next = NULL;
		tmp_st->next = tmp;
	}
}

int			check_garbage(char *s1, char *s2)
{
	if (!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rra"))
		return (1);
	if (!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "ra"))
		return (1);
	if (!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "rrb"))
		return (1);
	if (!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rb"))
		return (1);
	if (!ft_strcmp(s1, "pa") && !ft_strcmp(s2, "pb"))
		return (1);
	if (!ft_strcmp(s1, "pb") && !ft_strcmp(s2, "pa"))
		return (1);
	return (0);
}

void		del_list(t_pis *tmp1, t_pis *tmp2)
{
	ft_strdel(&tmp1->pisos);
	free(tmp1);
	tmp1 = NULL;
	ft_strdel(&tmp2->pisos);
	free(tmp2);
	tmp2 = NULL;
}

void		drop_rest(t_sta *sta)
{
	t_pis	*tmp;
	t_pis	*pactive;
	t_pis	*del;

	tmp = sta->pis;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		if (tmp->next && check_garbage(tmp->pisos, tmp->next->pisos))
		{
			pactive = tmp->next->next;
			tmp = tmp->prev;
			del = tmp->next;
			del_list(del, del->next);
			tmp->next = pactive;
			pactive->prev = tmp;
		}
		tmp = tmp->next;
	}
	return ;
}
