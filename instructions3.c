/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:18:10 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/02 15:24:35 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *s)
{
	int	temp;
	int	i;

	if (!s->size_a || !s->size_b)
		write(1, "illegal operation\n", 18);
	i = s->size_a - 1;
	temp = s->a[i++];
	while (--i > 0)
		s->a[i] = s->a[i - 1];
	s->a[i] = temp;
	i = s->size_b - 1;
	temp = s->b[i++];
	while (--i > 0)
		s->b[i] = s->b[i - 1];
	s->b[i] = temp;
	write(1, "rrr\n", 4);
}
