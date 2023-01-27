/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:40:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/01/27 19:11:27 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
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

void print_stack(int *stack)
{
	int i;

	i = -1;
	while (stack[++i])
		printf("%d\n", stack[i]);
}

int *fill_a_stack(char **argv)
{
	int count;
	int	*a_stack;
	
	count = 1;
	while (argv[count])
	{
		count += verify_and_count(argv[count]);
		if (count < 0)
			return (0);
	}
	a_stack = malloc(sizeof(int) * count + 1);
	while (count != -1)
	{
		a_stack[count - 1] = ft_atoi(argv[count]);
		count--;
	}
	return (a_stack);
}

int main(int argc, char **argv)
{
	int *a_stack;
	(void)argc;

	if (!&argv[1])
		return (write(1, "T'as po mis d'arguments pd", 26));
	a_stack = fill_a_stack(argv);
	if (!a_stack)
		return (write(2, "Error\n", 6));
	print_stack(a_stack);
	free(a_stack);
	a_stack = NULL;
	return (write(1, "gg\n", 3));
}