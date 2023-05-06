/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:54:44 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/06 19:55:00 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parser(char **argv, t_stack *s)
{
	int	atoi_error;
	int	i;

	atoi_error = 0;
	i = -1;
	if (multiple_args(argv))
		argv = ft_split(argv[1], ' ');
	s->size_a = arg_counter(&argv[1]);
	s->a = ft_calloc(sizeof(int), s->size_a + 1);
	if (!s->a)
		return (0);
	while (argv[1 + (++i)] && atoi_error != 1)
		s->a[i] = ft_atoi(argv[1 + i], &atoi_error);
	if (dbl(s) || atoi_error == 1)
		return (0);
	if (sorted(s))
		return (free(s->a), exit(0), 0);
	return (1);
}
