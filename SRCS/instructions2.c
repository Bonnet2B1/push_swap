/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:18:10 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/02 15:24:09 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *s)
{
	int	temp;
	int	i;

	if (!s->size_a)
		write(1, "illegal operation\n", 18);
	i = -1;
	temp = s->a[0];
	while (++i < s->size_a - 1)
		s->a[i] = s->a[i + 1];
	s->a[i] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *s)
{
	int	temp;
	int	i;

	if (!s->size_b)
		write(1, "illegal operation\n", 18);
	i = -1;
	temp = s->b[0];
	while (++i < s->size_b - 1)
		s->b[i] = s->b[i + 1];
	s->b[i] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *s)
{
	int	temp;
	int	i;

	if (!s->size_a || !s->size_b)
		write(1, "illegal operation\n", 18);
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
	write(1, "rr\n", 3);
}

void	rra(t_stack *s)
{
	int	temp;
	int	i;

	if (!s->size_a)
		write(1, "illegal operation\n", 18);
	i = s->size_a - 1;
	temp = s->a[i++];
	while (--i > 0)
		s->a[i] = s->a[i - 1];
	s->a[i] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *s)
{
	int	temp;
	int	i;

	if (!s->size_b)
		write(1, "illegal operation\n", 18);
	i = s->size_b - 1;
	temp = s->b[i++];
	while (--i > 0)
		s->b[i] = s->b[i - 1];
	s->b[i] = temp;
	write(1, "rrb\n", 4);
}
