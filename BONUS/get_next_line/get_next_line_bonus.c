/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:59:39 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/09 19:15:09 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup_gnl(char *buf, int *bufstart)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(sizeof(char) * (ft_strlen_gnl(buf, *bufstart) + 1));
	if (!line)
		return (NULL);
	while (buf[i + *bufstart])
	{
		line[i] = buf[i + *bufstart];
		i++;
		if (buf[i + *bufstart - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

void	ft_strjoin_part_two_gnl(char **line, char **buf, char **joined)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (line[0][i])
		joined[0][j++] = line[0][i++];
	while (buf[0][k])
	{
		joined[0][j++] = buf[0][k++];
		if (buf[0][k - 1] == '\n')
			break ;
	}
	joined[0][j] = '\0';
}

char	*ft_strjoin_gnl(char *line, char *buf, int *bufstart)
{
	char	*joined;

	joined = NULL;
	if (!line)
		return (ft_strdup_gnl(buf, bufstart));
	joined = malloc(sizeof(char) * (ft_strlen_gnl(line, 0) + ft_strlen_gnl(buf,
					*bufstart) + 1));
	if (joined)
		ft_strjoin_part_two_gnl(&line, &buf, &joined);
	else
		joined = NULL;
	free(line);
	line = NULL;
	return (joined);
}

int	get_next_line_part_two(int fd, char **buf, char **line, int *bufstart)
{
	int	bufend;

	while (checknl_gnl(*line))
	{
		if (!*bufstart)
		{
			bufend = read(fd, *buf, BUFFER_SIZE);
			if (bufend <= 0)
				break ;
			buf[0][bufend] = '\0';
		}
		*line = ft_strjoin_gnl(*line, *buf, bufstart);
		if (!*line)
			break ;
		*bufstart = get_buf_start_gnl(*buf, bufstart);
	}
	return (bufend);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	bufstart;
	char		*line;

	line = NULL;
	if (!buf)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		bufstart = 0;
	}
	if (get_next_line_part_two(fd, &buf, &line, &bufstart) >= 0
		&& line && *line)
		return (line);
	if (line)
		free(line);
	line = NULL;
	free(buf);
	buf = NULL;
	return (NULL);
}
