/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:40:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/04/14 16:17:50 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char **check_quotes(char **argv)
{
	int i;
	char *temp;
	// char *tempforfree;
	i = -1;
	while (argv[1][i++])
	{
		if (argv[1][i] == ' ' && argv[2] == NULL)
			return (NULL);
		else
		{	
			temp = ft_strdup(argv[1]); 
			freeall((void **)argv);
			return (ft_split(temp, ' '));
		}
	}
	free((void *)argv[0]);
	return (&argv[1]);
}

int *verify_and_fill_stack_a(char **argv)
{
	//double quotes (ça fait un seul argument)
	//check signe (pas de signe seul)
	//check double
	//check si la liste est déja triée
	//int min int max + (strlen < 10)
	if (!argv[1])
		return (0);
	argv = check_quotes(argv);
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

int thesmallest(int *stack)
{
	int i = 0;
	int thesmallest;

	thesmallest = stack[i];
	while (stack[i])
	{
		if (thesmallest > stack[i])
			thesmallest = stack[i];
		i++;
	}
	return (thesmallest);
}

int	algook(int *stack_a, int *stack_b)
{
	int i = 0;

	if (!stack_b || *stack_b)
		return (0);
	while (stack_a[i] && stack_a[i + 1])
	{
		if (stack_a[i] >= stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
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
	while (stack_b[0][0])
		pa(&*stack_a, &*stack_b);
	return (1);
}

int	findtheclosestthingbetween(int *stack, int start, int end)
{
	int i = -1;
	int a = -1;
	int b = -1;

	while (stack[++i] && a == -1)
	{
		if (stack[i] > start && stack[i] <= end)
			a = i;
	}
	i = stack_size(stack);
	while (--i >= 0 && b == -1)
	{
		if (stack[i] > start && stack[i] <= end)
			b = i;
	}
	if (a < (stack_size(stack) - b) && a != -1)
		return a;
	else if (b != -1)
		return b;
	else
		return (-1);
}

int findthebiggest(int *stack)
{
	int i = 0;
	int thebigone;
	int ret;

	ret = 0;
	thebigone = stack[i];
	while (stack[i])
	{
		if (thebigone < stack[i])
		{
			thebigone = stack[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

void	smartpush_to_b(int **stack_a, int **stack_b, int position)
{
	int stockage;

	stockage = stack_a[0][position];
	if (position <= stack_size(stack_a[0]) / 2)
	{
		while (stockage != stack_a[0][0])
			ra(&stack_a[0]);
		pb(&stack_a[0], &stack_b[0]);
	}
	else
	{
		while (stockage != stack_a[0][0])
			rra(&stack_a[0]);
		pb(&stack_a[0], &stack_b[0]);
	}
}

void	smartpush_to_a(int **stack_a, int **stack_b, int position)
{
	int stockage;

	stockage = stack_b[0][position];
	if (position <= stack_size(stack_b[0]) / 2)
	{
		while (stockage != stack_b[0][0])
			rb(&stack_b[0]);
		pa(&stack_a[0], &stack_b[0]);
	}
	else
	{
		while (stockage != stack_b[0][0])
		{
			rrb(&stack_b[0]);
			// print_stack('a', stack_a[0]);
			// print_stack('b', stack_b[0]);
		}
		pa(&stack_a[0], &stack_b[0]);
		// print_stack('a', stack_a[0]);
		// print_stack('b', stack_b[0]);
	}
}

// algo un peu plus opti
int	algobien(int **stack_a, int **stack_b)
{
	int stacksize = stack_size(stack_a[0]);
	int position;
	float a = 0;
	float multiplicateur = 0.33;
	while (a * multiplicateur < stacksize)
	{
		position = findtheclosestthingbetween(stack_a[0],a * stacksize , (a * stacksize) + multiplicateur * stacksize);
		while (position != -1)
		{
			smartpush_to_b(stack_a, stack_b, position);
			position = findtheclosestthingbetween(stack_a[0],a * stacksize , (a * stacksize) + multiplicateur * stacksize);
		}
		a += multiplicateur;
	}
	a = 0;
	multiplicateur = 0.2;
	while (a * multiplicateur < stacksize)
	{
		position = findtheclosestthingbetween(stack_b[0],a * stacksize , (a * stacksize) + multiplicateur * stacksize);
		while (position != -1)
		{
			smartpush_to_a(stack_a, stack_b, position);
			position = findtheclosestthingbetween(stack_b[0],a * stacksize , (a * stacksize) + multiplicateur * stacksize);
		}
		a += multiplicateur;
	}
	a = 0;
	multiplicateur = 0.05;
	while (a * multiplicateur < stacksize)
	{
		position = findtheclosestthingbetween(stack_a[0],a * stacksize , (a * stacksize) + multiplicateur * stacksize);
		while (position != -1)
		{
			smartpush_to_b(stack_a, stack_b, position);
			position = findtheclosestthingbetween(stack_a[0],a * stacksize , (a * stacksize) + multiplicateur * stacksize);
		}
		a += multiplicateur;
	}
	position = findthebiggest(stack_b[0]);
	while (stack_b[0][0])
	{
		smartpush_to_a(stack_a, stack_b, position);
		position = findthebiggest(stack_b[0]);
	}
	return (1);
}

int main(int argc, char **argv)
{
	int *stack_a;
	int *stack_b;
	int i = -1;

	stack_b = NULL;
	(void)argc;
	if (!argv[1])
		return (1);
	stack_a = verify_and_fill_stack_a(argv);
	if (!stack_a)
		return (write(2, "Error\n", 6));
	while (argv[++i])
		printf("%s\n", argv[i]);
	// print_stack('a', stack_a);
	// print_stack('b', stack_b);
	// algonul(&stack_a, &stack_b);
	// algobien(&stack_a, &stack_b);
	// print_stack('a', stack_a);
	// print_stack('b', stack_b);
	system("leaks push_swap");
	return (1);
}
