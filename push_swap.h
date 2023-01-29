/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:44:56 by edelarbr          #+#    #+#             */
/*   Updated: 2023/01/29 17:08:27 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_swap(int *a, int *b);
int		stack_size(int *stack);
int		ft_atoi(char *str);
int		verify_and_count(char *str);
void	print_stack(char *contexte, int *stack);
int		*fill_a_stack(char **argv);
void	freeall(int **thing);

//	Instructions
void	sa(int **stack_a);
void	sb(int **stack_b);
void	ss(int **stack_a, int **stack_b);
void	pa(int **stack_a, int **stack_b);
void	pb(int **stack_a, int **stack_b);
