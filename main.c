/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:40:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/01/31 22:52:01 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void freeall(int **thing)
{
	int i;

	i = 0;
	while (thing[++i])
	{
		free(thing[i]);
		thing[i] = NULL;
	}
	if (thing)
		free(thing);
	thing = NULL;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_swap(int *a, int *b)
{
	int	x;

	x = *b;
	*b = *a;
	*a = x;
}

int stack_size(int *stack)
{
	int i;

	i = 0;
	while (stack && stack[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (sign * nbr);
}

int verify_and_count(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-2147483648);
		i++;
	}
	return (1);
}

void print_stack(char stackname, int *stack)
{
	int i;

	i = -1;
	write (1, &stackname, 1);
	write (1, " : ", 3);
	if (stack && *stack)
	{
		while (stack[++i])
			printf("%d ", stack[i]);
		printf("\n");
	}
	else
		printf("vide\n");
}

int check_double(const int *stack)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (stack[++i])
	{
		while (stack[++j])
		{
			if (stack[i] == stack[j] && i != j)
				return 0;
		}
		j = -1;
	}
	return (1);
}

int *fill_stack_a(char **argv)
{
	int count;
	int	*stack_a;
	
	count = 1;
	while (argv[count])
	{
		count += verify_and_count(argv[count] + 1);
		if (count < 0)
			return (0);
	}
	stack_a = ft_calloc(sizeof(int), count + 1);
	while (count != -1)
	{
		stack_a[count - 1] = ft_atoi(argv[count]);
		count--;
	}
	if (check_double(stack_a))
		return (stack_a);
	return (0);
}

int isthesmallest(int n, int *stack)
{
	int i = -1;

	while (stack[++i])
		if (stack[i] < n)
			return (0);
	return 1;
}

int	thebiggest(int *stack)
{
	int thebigone;

	thebigone = *stack;
	while (*stack)
	{
		if (thebigone < *stack)
			thebigone = *stack;
		stack++;
	}
	return (thebigone);
}

int thesmallest(int *stack)
{
	int thesmallest;

	thesmallest = *stack;
	while (*stack)
	{
		if (thesmallest > *stack)
			thesmallest = *stack;
		stack++;
	}
	return (thesmallest);
}
int isinfirsthalf(int n, int *stack, int half)
{
	int i = -1;

	while (stack[++i])
		if (n >= thesmallest(stack) || n <= half)
			return (1);
	return (0);	
}

int isinsecondhalf(int n, int *stack, int half)
{
	int i = -1;

	while (stack[++i])
		if (n >= half || n <= thebiggest(stack))
			return (1);
	return (0);
}

// algo pas opti
int	algonul(int **stack_a, int **stack_b)
{
	while(stack_a[0][0])
	{
		while (!isthesmallest(**stack_a, *stack_a))
			ra(&*stack_a);
		pb(&*stack_a, &*stack_b);
	}
	while(stack_b[0][0])
		pa(&*stack_a, &*stack_b);
	// print_stack('a', *stack_a);
	// print_stack('b', *stack_b);
	return (1);
}

// algo un peu plus opti
int	algohalf(int **stack_a, int **stack_b)
{
	int size;
	int half;
	int count;

	size = stack_size(*stack_a);
	half = size / 2;
	count = half;
	while (stack_a[0][0])
	{
		while (count)
		{

			while (!isinfirsthalf(**stack_a, *stack_a, half))
				ra(&*stack_a);
			pb(&*stack_a, &*stack_b);		
			count--;
		}
		while (!isinsecondhalf(**stack_a, *stack_a, half))
			ra(&*stack_a);
		pb(&*stack_a, &*stack_b);
	}
	// print_stack('a', *stack_a);
	// print_stack('b', *stack_b);
	return (1);
}

int main(int argc, char **argv)
{
	int *stack_a;
	int *stack_b;

	stack_b = NULL;
	(void)argc;
	if (!argv[1])
		return (1);
	stack_a = fill_stack_a(argv);
	if (!stack_a)
		return (write(2, "Error\n", 6));
	print_stack('a', stack_a);
	print_stack('b', stack_b);
	if (1)
		algonul(&stack_a, &stack_b);
	if (0)
		algohalf(&stack_a, &stack_b);
	print_stack('a', stack_a);
	print_stack('b', stack_b);
	return (1);
}