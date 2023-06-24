/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:34:12 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/24 19:41:12 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*s;
	t_cost	*c;

	c = NULL;
	if (argc == 1)
		return (exit(0), 0);
	s = malloc(sizeof(t_stack));
	if (!s)
		return (freeall(s, 0), 0);
	if (!parser(argv, s))
		return (freeall(s, 0), write(1, "Error\n", 6));
	c = malloc(sizeof(t_cost));
	algorithm(s, c);
	freeall(s, c);
}
