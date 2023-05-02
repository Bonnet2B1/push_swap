/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:18:10 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/02 15:23:41 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *s)
{
	if (s->size_a < 2)
		write(1, "illegal operation\n", 18);
	ft_swap(&s->a[0], &s->a[1]);
	write(1, "sa\n", 3);
}

void	sb(t_stack *s)
{
	if (s->size_b < 2)
		write(1, "illegal operation\n", 18);
	ft_swap(&s->b[0], &s->b[1]);
	write(1, "sb\n", 3);
}

void	ss(t_stack *s)
{
	if (s->size_a < 2 || s->size_b < 2)
		write(1, "illegal operation\n", 18);
	ft_swap(&s->a[0], &s->a[1]);
	ft_swap(&s->b[0], &s->b[1]);
	write(1, "ss\n", 3);
}

void	pa(t_stack *s)
{
	int	*new_stack_a;
	int	*new_stack_b;
	int	i;
	int	j;

	if (!s->size_b)
		write(1, "illegal operation\n", 18);
	i = -1;
	j = -1;
	new_stack_a = ft_calloc(sizeof(int), (s->size_a + 1));
	new_stack_b = ft_calloc(sizeof(int), (s->size_b - 1));
	new_stack_a[0] = s->b[0];
	while (++i < s->size_a)
		new_stack_a[i + 1] = s->a[i];
	while (++j < s->size_b - 1)
		new_stack_b[j] = s->b[j + 1];
	free(s->a);
	free(s->b);
	s->a = new_stack_a;
	s->b = new_stack_b;
	s->size_a += 1;
	s->size_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stack *s)
{
	int	*new_stack_b;
	int	*new_stack_a;
	int	i;
	int	j;

	if (!s->size_a)
		write(1, "illegal operation\n", 18);
	i = -1;
	j = -1;
	new_stack_b = ft_calloc(sizeof(int), (s->size_b + 1));
	new_stack_a = ft_calloc(sizeof(int), (s->size_a - 1));
	new_stack_b[0] = s->a[0];
	while (++i < s->size_b)
		new_stack_b[i + 1] = s->b[i];
	while (++j < s->size_a - 1)
		new_stack_a[j] = s->a[j + 1];
	free(s->b);
	free(s->a);
	s->b = new_stack_b;
	s->a = new_stack_a;
	s->size_b += 1;
	s->size_a -= 1;
	write(1, "pb\n", 3);
}
