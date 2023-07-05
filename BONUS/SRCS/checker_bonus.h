/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:08:43 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/05 19:10:08 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../get_next_line/get_next_line_bonus.h"


typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}		t_stack;

char	**ft_split(const char *s, char c);

int		parser(char **argv, t_stack *s);

void	*ft_calloc(size_t count, size_t size);
void	ft_swap(int *a, int *b);
int		ft_atoi(char *str, int *atoi_error);
int		ft_isascii(int c);
void	comparator(char *line, t_stack *s);

size_t	ft_strlen(const char *s);
int		arg_counter(char **argv);
int		zero_berfore_nbr(char *str);

int		multiple_args(char **argv, int *freeargv);
int		dbl(t_stack *s);
int		sorted(t_stack *s);
void	freeall(t_stack *s);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		reader(t_stack *s);

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
