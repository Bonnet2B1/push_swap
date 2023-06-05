/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:33:38 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/05 21:56:26 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// structure

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	*sortedtab;
	int	size_a;
	int	size_b;
	int	median;

}		t_stack;

typedef struct s_cost
{
	int	ra_cal;
	int	rb_cal;
	int	rr_cal;
	int	rra_cal;
	int	rrb_cal;
	int	rrr_cal;
	int	total_cal;
	int	ra_tmp;
	int	rb_tmp;
	int	rr_tmp;
	int	rra_tmp;
	int	rrb_tmp;
	int	rrr_tmp;
	int	total_tmp;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}		t_cost;

// ft_split.c
char	**ft_split(const char *s, char c);

// parser.c
int		parser(char **argv, t_stack *s);

// utils1.c
void	*ft_calloc(size_t count, size_t size);
void	ft_swap(int *a, int *b);
int		ft_atoi(char *str, int *error);
void	migration(t_stack *s);

// utils2.c
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
int		arg_counter(char **argv, int *error);
int		huge_arg(char **argv);
void	smallest_go_top(t_stack *s, int **stack, int stack_size);

// utils3.c
int		multiple_args(char **argv, int *freeargv);
int		dbl(t_stack *s);
int		sorted(t_stack *s);
int		indexofthesmallest(int **stack, int stack_size);

// utils4.c
int		biggestisontop(t_stack *s);
int		smallestisontop(t_stack *s);
void	costinit(t_cost *c);
int		totalcost(int index_b, t_stack *s, t_cost *c);
int		index_costless_mv(t_stack *s, t_cost *c);

// utils5.c
void	newcostless(t_cost *c);
int		best_place(t_stack *s, int value);
void	individual_cost(t_stack *s, t_cost *c, int index_a, int index_b);
void	up_cost(t_cost *c, int index_a, int index_b);
void	down_cost(t_stack *s, t_cost *c, int index_a, int index_b);

// utils6.c
void	newcostless_tmp(t_cost *c);
void	move(t_stack *s, t_cost *c);
void	freeall(t_stack *s, t_cost *c);

// algorithm.c
void	algorithm(t_stack *s, t_cost *c);

// lilsort.c
void	lilsort(t_stack *s);

//	Instructions
void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);
void	pa(t_stack *s);
void	pb(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);

#endif
