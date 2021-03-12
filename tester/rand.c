#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../libft/libft.h"

int	ary_check(int *ary, int n, int num)
{
	for (int i = 0; i < n; i++)
	{
		if (ary[i] == num)
			return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	int n = ft_atoi(argv[1]);
	int	*ary;
	int	num;
	srand(time(NULL));

	ary = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		num = rand() % (n + 1);
		while (ary_check(ary, i, num) == 0)
		{
			num = rand() % (n + 1);
		}
		ary[i] = num;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ary[i]);
	return (0);
}
