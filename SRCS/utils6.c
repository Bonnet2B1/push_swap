/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:11:00 by edelarbr          #+#    #+#             */
/*   Updated: 2023/04/28 18:33:47 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	newcostless_tmp(t_cost *c)
{
	c->ra_tmp =  c->ra_cal;
	c->rb_tmp =  c->rb_cal;
	c->rr_tmp =  c->rr_cal;
	c->rra_tmp = c->rra_cal;
	c->rrb_tmp = c->rrb_cal;
	c->rrr_tmp = c->rrr_cal;
	c->total_tmp = c->total_cal;
	c->ra_cal = 0;
	c->rb_cal = 0;
	c->rr_cal = 0;
	c->rra_cal = 0;
	c->rrb_cal = 0;
	c->rrr_cal = 0;
	c->total_cal = 2147483647;
}

void	move(t_stack *s, t_cost *c)
{
	while (c->rrr--)
		rrr(s);
	while (c->rr--)
		rr(s);
	while (c->rra--)
		rra(s);
	while (c->rrb--)
		rrb(s);
	while (c->ra--)
		ra(s);
	while (c->rb--)
		rb(s);
	pa(s);
}
