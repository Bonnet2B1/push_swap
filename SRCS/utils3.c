/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:08:13 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/09 18:25:32 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	multiple_args(char **argv, int *freeargv)
{
	int	i;

	i = -1;
	while (!argv[2] && argv[1][++i])
	{
		if (argv[1][i] == ' ')
		{
			*freeargv = 1;
			return (1);
		}
	}
	*freeargv = 0;
	return (0);
}

int	dbl(t_stack *s)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < s->size_a)
	{
		while (s->a[++j] && j != i)
		{
			if (s->a[i] == s->a[j])
				return (1);
		}
		j = -1;
	}
	return (0);
}

int	sorted(t_stack *s)
{
	int	i;

	i = -1;
	while (++i < s->size_a - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
	}
	return (1);
}

int	indexofthesmallest(int **stack, int stack_size)
{
	int	i;
	int	smallest;
	int	index;

	i = -1;
	smallest = stack[0][0];
	index = 0;
	while (++i < stack_size)
	{
		if (smallest > stack[0][i])
		{
			smallest = stack[0][i];
			index = i;
		}
	}
	return (index);
}
