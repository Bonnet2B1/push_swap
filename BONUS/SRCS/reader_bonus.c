/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_BONUS.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:50:34 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/07 00:09:17 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
