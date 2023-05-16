/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:54:44 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/16 19:32:35 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parser(char **argv, t_stack *s)
{
	int	atoi_error;
	int	i;
	int	freeargv;
	int	printindex = -1;

	atoi_error = 0;
	i = -1;
	if (multiple_args(argv, &freeargv))
		argv = ft_split(argv[1], ' ');
	s->size_a = arg_counter(&argv[1]);
	printf("s->size_a = %d\n", s->size_a);
	s->a = ft_calloc(sizeof(int), s->size_a);
	if (!s->a)
		return (0);
	while (argv[1 + (++i)] && atoi_error != 1)
	{
		if (!argv[1 + i][0])
			i++;
		s->a[i] = ft_atoi(argv[1 + i], &atoi_error, 0);
	}
	while (s->a[++printindex])
		printf("%d\n", s->a[printindex]);
		write(1, "jusqu' ici tout va bien\n", 24);
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
