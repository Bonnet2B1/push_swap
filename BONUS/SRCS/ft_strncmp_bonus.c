/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_BONUS.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:45:53 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/07 00:10:03 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (!ft_isascii(s1[i]) || !ft_isascii(s2[i]))
			i++;
		if ((s1[i] > s2[i]) || !s2[i])
			return (1);
		if ((s1[i] < s2[i]) || !s1[i])
			return (-1);
		i++;
	}
	return (0);
}
