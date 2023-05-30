/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:54:44 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/29 21:49:05 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	parser(char **argv, t_stack *s)
{
	int	error;
	int	i;
	int	freeargv;

	error = 0;
	i = -1;
	if (multiple_args(argv, &freeargv))
		argv = ft_split(argv[1], ' ');
	s->size_a = arg_counter(&argv[1]);
	s->a = ft_calloc(sizeof(int), s->size_a);
	if (!s->a)
		return (0);
	while (argv[1 + (++i)] && error != 1)
		s->a[i] = ft_atoi(argv[1 + i], &error);
	while (freeargv && i >= 1)
		free(argv[i--]);
	if (freeargv)
		free(argv);
	if (dbl(s) || error == 1)
		return (0);
	if (sorted(s))
		return (1);
	return (1);
}
