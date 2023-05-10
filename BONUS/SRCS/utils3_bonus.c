/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:08:13 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/10 19:14:43 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
		while (++j < s->size_a)
		{
			if (i == j)
				j++;
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

void	freeall(t_stack *s)
{
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
	if (s)
		free(s);
}
