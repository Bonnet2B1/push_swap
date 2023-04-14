#include "push_swap.h"

void print_stack(char stackname, int *stack)
{
	int i;

	i = -1;
	write (1, &stackname, 1);
	write (1, " : ", 3);
	if (stack && *stack)
	{
		while (stack[++i])
		{
			if (stack[i] < 10)
				printf(" %d ", stack[i]);
			else
				printf("%d ", stack[i]);
		}	
		printf("\n");
	}
	else
		printf("vide\n");
}

void	*ft_calloc(size_t size, size_t count)
{
	unsigned char	*s;
	size_t				i;

	i = -1;
	s = malloc(count * size);
	if (!s)
		return (NULL);
	while (++i < count * size)
		s[i] = 0;
	return (s);
}

void freeall(void **thing)
{
	int i;

	i = 0;
	while (thing[++i])
	{
		free(thing[i]);
		thing[i] = NULL;
	}
	if (thing)
		free(thing);
	thing = NULL;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_swap(int *a, int *b)
{
	int	x;

	x = *b;
	*b = *a;
	*a = x;
}

int stack_size(int *stack)
{
	int i;

	i = 0;
	while (stack && stack[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i++] = '\0';
	return (dup);
}