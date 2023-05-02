/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:01:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/02 16:12:32 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggestisontop(t_stack *s)
{
	int i;

	i = -1;
	while (++i < s->size_a)
	{
		if (s->a[i] > s->a[0])
		{
			return (0);
		}	
	}
	return (1);
}

int	smallestisontop(t_stack *s)
{
	int i;

	i = -1;
	while (++i < s->size_a)
	{
		if (s->a[i] < s->a[0])
			return (0);
	}
	return (1);
}

void	costinit(t_cost *c)
{
	c->ra_cal = 0;
	c->rb_cal = 0;
	c->rr_cal = 0;
	c->rra_cal = 0;
	c->rrb_cal = 0;
	c->rrr_cal = 0;
	c->total_cal = 2147483647;
	c->ra_tmp = 0;
	c->rb_tmp = 0;
	c->rr_tmp = 0;
	c->rra_tmp = 0;
	c->rrb_tmp = 0;
	c->rrr_tmp = 0;
	c->total_tmp = 2147483647;
	c->ra = 0;
	c->rb = 0;
	c->rr = 0;
	c->rra = 0;
	c->rrb = 0;
	c->rrr = 0;
	c->total = 2147483647;
}

int	totalcost(int index_b, t_stack *s, t_cost *c)
{
	individual_cost(s, c, best_place(s, s->b[index_b]), index_b);
		newcostless_tmp(c);
	up_cost(c, best_place(s, s->b[index_b]), index_b);
	if (c->total_cal < c->total_tmp)
		newcostless_tmp(c);
	down_cost(s, c, best_place(s, s->b[index_b]), index_b);
	if (c->total_cal < c->total_tmp)
		newcostless_tmp(c);
	return (c->total_tmp);
}

int	index_costless_mv(t_stack *s, t_cost *c)
{
	int i;
	int index;

	i = -1;
	costinit(c);
	while (++i < s->size_b)
	{
		if (totalcost(i, s, c) < c->total)
		{
			index = i;
			newcostless(c);
		}
	}
	return (index);
}
