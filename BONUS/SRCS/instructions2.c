/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:18:10 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/02 17:48:13 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *s)
{
	int	temp;
	int	i;

	if (!s->size_a)
	i = -1;
	temp = s->a[0];
	while (++i < s->size_a - 1)
		s->a[i] = s->a[i + 1];
	s->a[i] = temp;
}

void	rb(t_stack *s)
{
	int	temp;
	int	i;

	if (!s->size_b)
	i = -1;
	temp = s->b[0];
	while (++i < s->size_b - 1)
		s->b[i] = s->b[i + 1];
	s->b[i] = temp;
}

void	rr(t_stack *s)
{
	int	temp;
	int	i;

	if (!s->size_a || !s->size_b)
	i = -1;
	temp = s->a[0];
	while (++i < s->size_a - 1)
		s->a[i] = s->a[i + 1];
	s->a[i] = temp;
	i = -1;
	temp = s->b[0];
	while (++i < s->size_b - 1)
		s->b[i] = s->b[i + 1];
	s->b[i] = temp;
}

void	rra(t_stack *s)
{
	int	temp;
	int	i;

	if (!s->size_a)
	i = s->size_a - 1;
	temp = s->a[i++];
	while (--i > 0)
		s->a[i] = s->a[i - 1];
	s->a[i] = temp;
}

void	rrb(t_stack *s)
{
	int	temp;
	int	i;

	if (!s->size_b)
	i = s->size_b - 1;
	temp = s->b[i++];
	while (--i > 0)
		s->b[i] = s->b[i - 1];
	s->b[i] = temp;
}
