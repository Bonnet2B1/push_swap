/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:00:08 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/09 19:13:51 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_gnl(char *s, int bufstart)
{
	int	i;

	i = 0;
	while (s[i + bufstart])
	{
		i++;
		if (s[i + bufstart - 1] == '\n')
			break ;
	}
	return (i);
}

int	checknl_gnl(char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (1);
	while (line[++i])
	{
		if (line[i] == '\n')
			return (0);
	}
	return (1);
}

int	get_buf_start_gnl(char *buf, int *bufstart)
{
	int	new_bufstart;

	new_bufstart = -1;
	while (buf[++new_bufstart + *bufstart])
	{
		if (buf[new_bufstart + *bufstart] == '\n')
			return (new_bufstart + *bufstart + 1);
	}
	return (0);
}
