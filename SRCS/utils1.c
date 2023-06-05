/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:56:24 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/05 21:56:55 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t size, size_t count)
{
	unsigned char	*s;
	size_t			i;

	i = -1;
	s = malloc(count * size);
	if (!s)
		return (NULL);
	while (++i < count * size)
		s[i] = 0;
	return (s);
}

void	ft_swap(int *a, int *b)
{
	int	x;

	x = *b;
	*b = *a;
	*a = x;
}

int	ft_atoi(char *str, int *error)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
		if (!(str[i] >= '0' && str[i] <= '9'))
			*error = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - 48);
	if (str[i] || (ft_strlen(str) > 11) || (nbr
			* sign > 2147483647) || (nbr * sign < -2147483648))
		*error = 1;
	return (sign * nbr);
}

void	migration(t_stack *s)
{
	while (s->size_a > (s->size_a + s->size_b) / 2 + 2)
	{
		if (biggestisontop(s) || smallestisontop(s))
			ra(s);
		else if (s->a[0] < s->median + 1)
			pb(s);
		else
			ra(s);
	}
	while (s->size_a > 2)
	{
		if (biggestisontop(s) || smallestisontop(s))
			ra(s);
		else
			pb(s);
	}
}
