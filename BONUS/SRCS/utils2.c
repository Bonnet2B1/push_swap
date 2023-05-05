#include "push_swap_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int arg_counter(char **argv)
{
	int i;
	
	i = 0;
	while (argv[i])
		i++;
	return (i);
}
