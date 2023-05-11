/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:18:17 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/11 17:12:06 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*s;

	if (argc == 1)
		return (0);
	s = malloc(sizeof(t_stack));
	if (!s)
		return (freeall(s), 0);
	if (!parser(argv, s))
		return (freeall(s), write(1, "Error\n", 6));
	reader(s);
	if (sorted(s) && !s->size_b)
		return (freeall(s), write(1, "OK\n", 3));
	else
		return (freeall(s), write(1, "KO\n", 3));
}
