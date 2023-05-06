/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:18:10 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/07 00:36:58 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *s)
{
	if (s->size_a < 2)
		return ;
	ft_swap(&s->a[0], &s->a[1]);
}

void	sb(t_stack *s)
{
	if (s->size_b < 2)
		return ;
	ft_swap(&s->b[0], &s->b[1]);
}

void	ss(t_stack *s)
{
	if (s->size_a < 2 || s->size_b < 2)
		return ;
	ft_swap(&s->a[0], &s->a[1]);
	ft_swap(&s->b[0], &s->b[1]);
}

void	pa(t_stack *s)
{
	int	*new_stack_a;
	int	*new_stack_b;
	int	i;
	int	j;

	if (!s->size_b)
		return ;
	i = -1;
	j = -1;
	new_stack_a = ft_calloc(sizeof(int), (s->size_a + 1));
	new_stack_b = ft_calloc(sizeof(int), (s->size_b - 1));
	new_stack_a[0] = s->b[0];
	while (++i < s->size_a)
		new_stack_a[i + 1] = s->a[i];
	while (++j < s->size_b - 1)
		new_stack_b[j] = s->b[j + 1];
	free(s->a);
	free(s->b);
	s->a = new_stack_a;
	s->b = new_stack_b;
	s->size_a += 1;
	s->size_b -= 1;
}

void	pb(t_stack *s)
{
	int	*new_stack_b;
	int	*new_stack_a;
	int	i;
	int	j;

	if (!s->size_a)
		return ;
	i = -1;
	j = -1;
	new_stack_b = ft_calloc(sizeof(int), (s->size_b + 1));
	new_stack_a = ft_calloc(sizeof(int), (s->size_a - 1));
	new_stack_b[0] = s->a[0];
	while (++i < s->size_b)
		new_stack_b[i + 1] = s->b[i];
	while (++j < s->size_a - 1)
		new_stack_a[j] = s->a[j + 1];
	free(s->b);
	free(s->a);
	s->b = new_stack_b;
	s->a = new_stack_a;
	s->size_b += 1;
	s->size_a -= 1;
}
