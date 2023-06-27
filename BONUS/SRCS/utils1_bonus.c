/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:13:53 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/28 00:08:03 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	ft_atoi(char *str, int *atoi_error)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!str[i] || zero_berfore_nbr(str))
		return (*atoi_error = 1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (*atoi_error = 1);
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - 48);
	if (str[i] || ft_strlen(str) > 11
		|| (nbr * sign > 2147483647) || (nbr * sign < -2147483648))
		return (*atoi_error = 1);
	return (sign * nbr);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

void	comparator(char *line, t_stack *s)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(s);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(s);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(s);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(s);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(s);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(s);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(s);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(s);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(s);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(s);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(s);
	else
		return (write(2, "Error\n", 6), exit(0));
}
