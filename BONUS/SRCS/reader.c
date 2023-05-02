/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:50:34 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/02 18:05:53 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../get_next_line/get_next_line.h"

int reader(t_stack *s)
{
	char *gnl_ret;

	gnl_ret = NULL;
	while(1)
	{
		gnl_ret = get_next_line(0);
		if (ft_strncmp(gnl_ret, "sa\n", 3) = 0)
			sa(s);
		else if (ft_strncmp(gnl_ret, "sb\n", 3) = 0)
			sb(s);
		else if (ft_strncmp(gnl_ret, "ss\n", 3) = 0)
			ss(s);
		else if (ft_strncmp(gnl_ret, "pa\n", 3) = 0)
			pa(s);
		else if (ft_strncmp(gnl_ret, "pb\n", 3) = 0)
			pb(s);
		else if (ft_strncmp(gnl_ret, "ra\n", 3) = 0)
			ra(s);
		else if (ft_strncmp(gnl_ret, "rb\n", 3) = 0)
			rb(s);
		else if (ft_strncmp(gnl_ret, "rr\n", 3) = 0)
			rr(s);
		else if (ft_strncmp(gnl_ret, "rra\n", 4) = 0)
			rra(s);
		else if (ft_strncmp(gnl_ret, "rrb\n", 4) = 0)
			rrb(s);
		else if (ft_strncmp(gnl_ret, "rrr\n", 4) = 0)
			rrr(s);
		else
			return (write(2, "Error\n", 6), exit(0));
	}
	return (0);
}
