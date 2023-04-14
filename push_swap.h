/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:44:56 by edelarbr          #+#    #+#             */
/*   Updated: 2023/04/14 14:27:09 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_swap(int *a, int *b);
int		stack_size(int *stack);
int		ft_atoi(char *str);
int		verify_and_count(char *str);
void print_stack(char stackname, int *stack);
int		*fill_a_stack(char **argv);
void	freeall(void **thing);
char	*ft_strdup(const char *src);

//	Instructions
void	sa(int **stack_a);
void	sb(int **stack_b);
void	ss(int **stack_a, int **stack_b);
void	pa(int **stack_a, int **stack_b);
void	pb(int **stack_a, int **stack_b);
void	ra(int **stack_a);
void	rb(int **stack_b);
void	rr(int **stack_a, int **stack_b);
void	rra(int **stack_a);
void	rrb(int **stack_b);
void	rrr(int **stack_a, int ** stack_b);
