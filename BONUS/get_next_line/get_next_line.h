/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:00:03 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/07 00:51:42 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen_gnl(char *s, int bufstart);
int		checknl_gnl(char *line);
int		get_buf_start_gnl(char *buf, int *bufstart);
char	*ft_strdup_gnl(char *buf, int *bufstart);
void	ft_strjoin_part_two_gnl(char **line, char **buf, char **joined);
char	*ft_strjoin_gnl(char *line, char *buf, int *bufstart);
int		get_next_line_part_two(int fd, char **buf, char **line, int *bufstart);
char	*get_next_line(int fd);

#endif
