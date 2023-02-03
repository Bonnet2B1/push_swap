/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:18:10 by edelarbr          #+#    #+#             */
/*   Updated: 2023/02/03 20:40:33 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.

void	sa(int **stack_a)
{
	if (!stack_a[0][1])
		return ;
	ft_swap(&stack_a[0][0], &stack_a[0][1]);
	write(1, "sa\n", 3);
}

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.

void	sb(int **stack_b)
{
	if (!stack_b[0][1])
		return ;
	ft_swap(&stack_b[0][0], &stack_b[0][1]);
	write(1, "sa\n", 3);
}

// ss : sa et sb en même temps.

void	ss(int **stack_a, int **stack_b)
{
	if (!stack_a[0][1] || !stack_b[0][1])
		return ;
	ft_swap(&stack_a[0][0], &stack_a[0][1]);
	ft_swap(&stack_b[0][0], &stack_b[0][1]);
	write(1, "ss\n", 3);
}

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.

void	pa(int **stack_a, int **stack_b)
{
	int *new_stack_a;
	int *new_stack_b;
	int i;
	int j;

	if (!**stack_b)
		return ;
	i = -1;
	j = -1;
	new_stack_a = ft_calloc(sizeof(int), (stack_size(*stack_a) + 2));
	new_stack_b = ft_calloc(sizeof(int), stack_size(*stack_b));
	new_stack_a[0] = stack_b[0][0];
	while(stack_a[0][++i])
		new_stack_a[i + 1] = stack_a[0][i];
	while(*stack_b && stack_b[0][++j + 1])
		new_stack_b[j] = stack_b[0][j + 1];
	free(*stack_a);
	free(*stack_b);
	*stack_a = new_stack_a;
	*stack_b = new_stack_b;
	write(1, "pa\n", 3);
}

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.

void	pb(int **stack_a, int **stack_b)
{
	int *new_stack_b;
	int *new_stack_a;
	int i;
	int j;

	if (!**stack_a)
		return ;
	i = -1;
	j = -1;
	new_stack_b = ft_calloc(sizeof(int), (stack_size(*stack_b) + 2));
	new_stack_a = ft_calloc(sizeof(int), stack_size(*stack_a));
	new_stack_b[0] = stack_a[0][0];
	while(stack_b[0] && stack_b[0][++i])
		new_stack_b[i + 1] = stack_b[0][i];
	while(*stack_a && stack_a[0][++j + 1])
		new_stack_a[j] = stack_a[0][j + 1];
	free(*stack_b);
	free(*stack_a);
	*stack_b = new_stack_b;
	*stack_a = new_stack_a;
	write(1, "pa\n", 3);
}

// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.

void	ra(int **stack_a)
{
	int	temp;
	int i;

	if (!*stack_a)
		return ;
	i = -1;
	temp = stack_a[0][0];
	while (stack_a[0][++i + 1])
		stack_a[0][i] = stack_a[0][i + 1];
	stack_a[0][i] = temp;
	write(1, "ra\n", 3);
}

// rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.

void	rb(int **stack_b)
{
	int	temp;
	int i;

	if (!*stack_b)
		return ;
	i = -1;
	temp = stack_b[0][0];
	while (stack_b[0][++i + 1])
		stack_b[0][i] = stack_b[0][i + 1];
	stack_b[0][i] = temp;
	write(1, "rb\n", 3);
}

// rr : ra et rb en même temps.

void	rr(int **stack_a, int **stack_b)
{
	int	temp;
	int i;

	if (!*stack_a || !*stack_b)
		return ;
	i = -1;
	temp = stack_a[0][0];
	while (stack_a[0][++i + 1])
		stack_a[0][i] = stack_a[0][i + 1];
	stack_a[0][i] = temp;
	i = -1;
	temp = stack_b[0][0];
	while (stack_b[0][++i + 1])
		stack_b[0][i] = stack_b[0][i + 1];
	stack_b[0][i] = temp;
	write(1, "rr\n", 3);
}

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.

void	rra(int **stack_a)
{
	int	temp;
	int i;

	if (!*stack_a)
		return ;
	i = stack_size(*stack_a) - 1;
	temp = stack_a[0][i++];
	while (--i > 0)
		stack_a[0][i] = stack_a[0][i - 1];
	stack_a[0][i] = temp;
	write(1, "rra\n", 4);
}

// rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
// la pile b. Le dernier élément devient le premier.

void	rrb(int **stack_b)
{
	int	temp;
	int i;

	if (!*stack_b)
		return ;
	i = stack_size(*stack_b) - 1;
	temp = stack_b[0][i++];
	while (--i > 0)
		stack_b[0][i] = stack_b[0][i - 1];
	stack_b[0][i] = temp;
	write(1,"rrb\n", 4);
}

// rrr : rra et rrb en même temps.

void	rrr(int **stack_a, int ** stack_b)
{
	int	temp;
	int i;

	if (!*stack_a || !*stack_b)
		return ;
	i = stack_size(*stack_a) - 1;
	temp = stack_a[0][i++];
	while (--i > 0)
	stack_a[0][i] = stack_a[0][i - 1];
	stack_a[0][i] = temp;
	write(1, "rra\n", 4);
	i = stack_size(*stack_b) - 1;
	temp = stack_b[0][i++];
	while (--i > 0)
		stack_b[0][i] = stack_b[0][i - 1];
	stack_b[0][i] = temp;
	write(1, "rrr\n", 4);
}
