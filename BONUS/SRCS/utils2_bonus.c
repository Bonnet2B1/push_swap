/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:12:02 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/28 00:09:00 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	arg_counter(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	zero_berfore_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] == '0')
	{
		if (str[i] && str[i + 1] >= '0' && str[i + 1] <= '9')
			return (1);
		i++;
	}
	return (0);
}
