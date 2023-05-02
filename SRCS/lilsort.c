/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lilsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:03:07 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/02 15:21:58 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *s)
{
	if (s->a[0] > s->a[1])
		sa(s);
}

void	sort3(t_stack *s)
{
	if (s->a[2] > s->a[0] && s->a[0] > s->a[1])
		sa(s);
	else if (s->a[0] > s->a[2] && s->a[1] > s->a[0])
		rra(s);
	else if (s->a[1] > s->a[0] && s->a[1] > s->a[2])
	{
		rra(s);
		sa(s);
	}
	else if (s->a[0] > s->a[1] && s->a[1] > s->a[2])
	{
		sa(s);
		rra(s);
	}
	else if (s->a[0] > s->a[1] && s->a[2] > s->a[1])
		ra(s);
}

void	sort4(t_stack *s)
{
	smallest_go_top(s, &s->a, s->size_a);
	pb(s);
	sort3(s);
	pa(s);
}

void	sort5(t_stack *s)
{
	smallest_go_top(s, &s->a, s->size_a);
	pb(s);
	smallest_go_top(s, &s->a, s->size_a);
	pb(s);
	sort3(s);
	pa(s);
	pa(s);
}

void	lilsort(t_stack *s)
{
	if (s->size_a == 1)
		return ;
	else if (s->size_a == 2)
		sort2(s);
	else if (s->size_a == 3)
		sort3(s);
	else if (s->size_a == 4)
		sort4(s);
	else if (s->size_a == 5)
		sort5(s);
}
