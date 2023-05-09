/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:18:17 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/09 19:18:25 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*s;

	(void)argc;
	s = malloc(sizeof(t_stack));
	parser(argv, s);
	if (!parser(argv, s))
		return (write(1, "Error\n", 6));
	reader(s);
	if (sorted(s) && !s->size_b)
		return (write(1, "OK\n", 3));
	else
		return (write(1, "KO\n", 3));
}
// penser à free gnl