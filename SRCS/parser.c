/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:54:44 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/24 19:52:55 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parser(char **argv, t_stack *s)
{
	int	atoi_error;
	int	i;
	int	freeargv;

	atoi_error = 0;
	i = -1;
	if (multiple_args(argv, &freeargv))
		argv = ft_split(argv[1], ' ');
	s->size_a = arg_counter(&argv[1]);
	s->a = ft_calloc(sizeof(int), s->size_a);
	if (!s->a)
		return (0);
	while (1 + (++i) <= s->size_a && atoi_error != 1)
		s->a[i] = ft_atoi(argv[1 + i], &atoi_error);
	while (freeargv && i >= 1)
		free(argv[i--]);
	if (freeargv)
		free(argv);
	if (dbl(s) || atoi_error == 1)
		return (0);
	if (sorted(s)) 
		return (freeall(s, 0), exit(0), 0);
	return (1);
}
