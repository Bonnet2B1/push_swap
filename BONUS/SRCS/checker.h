/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:08:43 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/07 00:09:14 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"

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

// ft_split.c
char	**ft_split(const char *s, char c);

// parser.c
int		parser(char **argv, t_stack *s);

// utils1.c
void	*ft_calloc(size_t count, size_t size);
void	ft_swap(int *a, int *b);
int		ft_atoi(char *str, int *atoi_error);
int		ft_isascii(int c);
void	comparator(char *line, t_stack *s);

// utils2.c
size_t	ft_strlen(const char *s);
int		arg_counter(char **argv);

// utils3.c
int		multiple_args(char **argv);
int		dbl(t_stack *s);
int		sorted(t_stack *s);

// ft_strncmp.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// reader.c
int		reader(t_stack *s);

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
