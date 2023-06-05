/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:23:36 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/05 22:26:15 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i++] = '\0';
	return (dup);
}

int	arg_counter(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	smallest_go_top(t_stack *s, int **stack, int stack_size)
{
	if (indexofthesmallest(stack, stack_size) <= stack_size / 2)
	{
		while (indexofthesmallest(stack, stack_size) != 0)
			ra(s);
	}
	else if (indexofthesmallest(stack, stack_size) >= stack_size / 2)
	{
		while (indexofthesmallest(stack, stack_size) != 0)
			rra(s);
	}
}
