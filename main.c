/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:40:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/01/29 17:08:58 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (stack[i])
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

void print_stack(char *contexte, int *stack)
{
	int i;

	i = -1;
	write (1, contexte, ft_strlen(contexte));
	write (1, "\n", 1);
	while (stack[++i])
		printf("%d ", stack[i]);
	printf("\n\n");
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
	stack_a = malloc(sizeof(int) * count + 1);
	stack_a[count] = 0;
	while (count != -1)
	{
		stack_a[count - 1] = ft_atoi(argv[count]);
		count--;
	}
	return (stack_a);
}

int main(int argc, char **argv)
{
	int *stack_a;
	int *stack_b;

	stack_b = malloc(sizeof(int) * 4);
	stack_b[0] = 4;
	stack_b[1] = 5;
	stack_b[2] = 6;
	stack_b[3] = 0;
	(void)argc;

	if (!&argv[1])
		return (write(1, "T'as po mis d'arguments pd", 26));
	stack_a = fill_stack_a(argv);
	if (!stack_a)
		return (write(2, "Error\n", 6));
	print_stack("\nstack a :", stack_a);
	print_stack("stack b :", stack_b);
	sa(&stack_a);
	print_stack("\nstack a :", stack_a);
	print_stack("stack b :", stack_b);
	pa(&stack_a, &stack_b);
	print_stack("\nstack a :", stack_a);
	print_stack("stack b :", stack_b);
	free(stack_a);
	stack_a = NULL;
	return (write(1, "gg\n", 3));
}