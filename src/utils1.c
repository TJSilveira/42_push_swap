#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	indexator(int *array, int size)
{
	int	order;
	int	i;
	int	j;
	int	*output;

	i = size;
	j = 0;
	output = malloc(sizeof(int) * size);
	if (!output)
		exit(1);
	while (--i >= 0)
	{
		j = size - 1;
		order = 0;
		while (j >= 0)
		{
			if (array[i] > array[j] /*|| ((array[i] == array[j]) && (i > j))*/)
				order++;
			j--;
		}
		output[i] = order;
	}
	i = -1;
	while (++i < size)
		array[i] = output[i];
	free(output);
}