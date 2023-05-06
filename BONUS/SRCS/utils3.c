/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:08:13 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/07 00:36:58 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	multiple_args(char **argv)
{
	int	i;

	i = -1;
	while (!argv[2] && argv[1][++i])
	{
		if (argv[1][i] == ' ')
			return (1);
	}
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

