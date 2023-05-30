/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:34:12 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/29 22:10:16 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// dans freeall mettre if (s) au début des free de s et laisser free(s) à la fin des free s

// gérer ./push_swap "" "" (atoi error doit etre = à 1
// OK : gérer ./push_swap 000000002 000000000000000000000000000000001 (retirer les 0 avant le parse du strlen > 11
int	main(int argc, char **argv)
{
	t_stack	*s;
	t_cost	*c;

	c = NULL;
	if (argc == 1)
		return (exit(0), 0);
	s = malloc(sizeof(t_stack));
	if (!s)
		return (freeall(s, 0), 0);
	if (!parser(argv, s))
		return (freeall(s, 0), write(1, "Error\n", 6));
	c = malloc(sizeof(t_cost));
	algorithm(s, c);
	freeall(s, c);
}
