/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:50:34 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/05 17:34:15 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "push_swap_bonus.h"

int	reader(t_stack *s)
{
	char	*line;

	line = NULL;
	line = get_next_line(0);
	while (line)
	{
		comparator(line, s);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}
