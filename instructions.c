/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:18:10 by edelarbr          #+#    #+#             */
/*   Updated: 2023/01/29 15:17:08 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.

void	sa(int **stack_a)
{
	if (!*stack_a[1])
		return ;
	ft_swap(&stack_a[0][0], &stack_a[0][1]);
	write(1, "sa\n", 3);
}

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.

void	sb(int **stack_b)
{
	if (!*stack_b[1])
		return ;
	ft_swap(&stack_b[0][0], &stack_b[0][1]);
	write(1, "sa\n", 3);
}

// ss : sa et sb en même temps.

void	ss(int **stack_a, int **stack_b)
{
	if (!stack_a[1] || !stack_b[1])
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
	new_stack_a = malloc(sizeof(int) * (stack_size(*stack_a) + 2));
	new_stack_b = malloc(sizeof(int) * stack_size(*stack_b));
	new_stack_a[0] = stack_b[0][0];
	while(stack_a[0][++i])
		new_stack_a[i + 1] = stack_a[0][i];
	new_stack_a[++i] = 0;
	while(stack_b[0][(++j) + 1])
		new_stack_b[j] = stack_b[0][j + 1];
	new_stack_b[++j] = 0;
	free(*stack_a);
	free(*stack_b);
	*stack_a = new_stack_a;
	*stack_b = new_stack_b;
	write(1, "pa\n", 3);
}

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.

// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.

// rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.

// rr : ra et rb en même temps.

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.

// rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
// la pile b. Le dernier élément devient le premier.

// rrr : rra et rrb en même temps.
