/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:45:44 by edelarbr          #+#    #+#             */
/*   Updated: 2023/04/28 22:00:37 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	newcostless(t_cost *c)
{
	c->ra =  c->ra_tmp;
	c->rb =  c->rb_tmp;
	c->rr =  c->rr_tmp;
	c->rra = c->rra_tmp;
	c->rrb = c->rrb_tmp;
	c->rrr = c->rrr_tmp;
	c->total = c->total_tmp;
	c->ra_tmp = 0;
	c->rb_tmp = 0;
	c->rr_tmp = 0;
	c->rra_tmp = 0;
	c->rrb_tmp = 0;
	c->rrr_tmp = 0;
	c->total_tmp = 2147483647;
}

int		best_place(t_stack *s, int value) // retourne l'index de la valeur à mettre au top de la stack a
{
	int i;

	i = 0;
	while (++i < s->size_a)
	{
		if (s->a[i] > value && s->a[i - 1] < value)
			return (i);
	}
	return (0);
}

void	individual_cost(t_stack *s, t_cost *c, int index_a, int index_b)
{
	if (index_a >= s->size_a / 2)
		c->rra_cal = s->size_a - index_a;
	else
		c->ra_cal = index_a;
	if (index_b >= s->size_b / 2)
		c->rrb_cal = s->size_b - index_b;
	else
		c->rb_cal = index_b;
	while (c->ra_cal && c->rb_cal)
	{
		c->ra_cal--;
		c->rb_cal--;
		c->rr_cal++;
	}
	while (c->rra_cal && c->rrb_cal)
	{
		c->rra_cal--;
		c->rrb_cal--;
		c->rrr_cal++;
 	}
	c->total_cal = c->ra_cal + c->rb_cal + c->rr_cal + c->rra_cal + c->rrb_cal + c->rrr_cal;
}

void	up_cost(t_cost *c, int index_a, int index_b)
{
	c->ra_cal = index_a;
	c->rb_cal = index_b;
	c->rr_cal = 0;
	c->rra_cal = 0;
	c->rrb_cal = 0;
	c->rrr_cal = 0;
	while (c->ra_cal && c->rb_cal)
	{
		c->ra_cal--;
		c->rb_cal--;
		c->rr_cal++;
	}
	c->total_cal = c->ra_cal + c->rb_cal + c->rr_cal;
}

void	down_cost(t_stack *s, t_cost *c, int index_a, int index_b)
{
	c->ra_cal = 0;
	c->rb_cal = 0;
	c->rr_cal = 0;
	c->rra_cal = s->size_a - index_a;
	c->rrb_cal = s->size_b - index_b;
	c->rrr_cal = 0;
	while (c->rra_cal && c->rrb_cal)
	{
		c->rra_cal--;
		c->rrb_cal--;
		c->rrr_cal++;
 	}
	c->total_cal = c->rra_cal + c->rrb_cal + c->rrr_cal;
}
