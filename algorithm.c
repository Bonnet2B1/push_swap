/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:44:19 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/02 15:18:56 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *s)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = s->a[0];
	while (++i < s->size_a)
	{
		if (s->a[i] < smallest)
			smallest = s->a[i];
	}
	return (smallest);
}

int	find_biggest(t_stack *s)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = s->a[0];
	while (++i < s->size_a)
	{
		if (s->a[i] > biggest)
			biggest = s->a[i];
	}
	return (biggest);
}

int	find_median(t_stack *s)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	s->sortedtab = malloc(sizeof(int) * s->size_a);
	while (++i < s->size_a)
		s->sortedtab[i] = s->a[i];
	i = -1;
	while (++i < s->size_a)
	{
		j = i + 1;
		while (j < s->size_a)
		{
			if (s->sortedtab[i] > s->sortedtab[j])
			{
				tmp = s->sortedtab[i];
				s->sortedtab[i] = s->sortedtab[j];
				s->sortedtab[j] = tmp;
			}
			j++;
		}
	}
	return (s->sortedtab[s->size_a / 2]);
}

void	algorithm(t_stack *s, t_cost *c)
{
	s->b = NULL;
	s->size_b = 0;
	s->median = find_median(s);
	if (s->size_a <= 5)
		return (lilsort(s));
	migration(s);
	while (s->size_b)
	{
		index_costless_mv(s, c);
		move(s, c);
	}
	smallest_go_top(s, &s->a, s->size_a);
}
