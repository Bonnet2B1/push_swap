#include "push_swap.h"

void	*ft_calloc(size_t size, size_t count)
{
	unsigned char	*s;
	size_t				i;

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
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] || ft_strlen(str) > 11 || (nbr * sign > 2147483647) || (nbr * sign < -2147483648))
	{
		*atoi_error = 1;
		return (0);
	}
	return (sign * nbr);
}

void print_stacks(t_stack *s)
{
	int i;

	i = -1;
	printf("a: ");
	if (s->size_a == 0)
		printf("empty\n");
	else
	{
		while (++i < s->size_a)
			printf("%d ", s->a[i]);
		printf("\n");
	}
	i = -1;
	printf("b: ");
	if (s->size_b == 0)
		printf("empty\n");
	else
	{
		while (++i < s->size_b)
			printf("%d ", s->b[i]);
		printf("\n");
	}
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
