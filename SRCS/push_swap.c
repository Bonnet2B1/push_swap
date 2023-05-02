/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:34:12 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/02 18:25:43 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*s;
	t_cost	*c;

	(void)argc;
	s = malloc(sizeof(t_stack));
	c = malloc(sizeof(t_cost));
	parser(argv, s);
	if (!parser(argv, s))
		return (write(1, "Error\n", 6));
	algorithm(s, c);
}
