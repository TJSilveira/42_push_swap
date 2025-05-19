#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	ft_10power(int exp)
{
	int	i;
	int	output;

	i = 1;
	output = 10;
	if (exp == 0)
		return (1);
	while (i < exp)
	{
		output *= 10;
		i++;
	}
	return (output);
}

int	find_max(int *array, int size)
{
	int	i;
	int max;
	int	digits;

	i = 0;
	max = 0;
	digits = 0;
	while (++i < size)
	{
		if (ABS(array[i]) > ABS(array[max]))
			max = i;
	}
	digits = 0;
	while (ABS(array[max])/ft_10power(digits) > 9 )
		digits++;
	return (digits);
}

void	radix_sort(int **array, int size)
{
	int	*output;
	int	counter[19];
	int	i;
	// int	exp_max;
	int	exp_cur;

	output = malloc(sizeof(int) * size);
	if (!output)
		exit (1);
	i = -1;
	while (++i < 19)
		counter[i] = 0;
	// exp_max = find_max(*array, size);
	exp_cur = 0;
	i = -1;
	while (++i < size)
		counter[(((*array)[i] / ft_10power(exp_cur)) % 10) + 9]++;
	i = 1;
	while (i < 19)
	{
		counter[i] += counter[i - 1];
		i++;
	}
	i = 0;
	while (i < 19)
	{
		counter[i]--;
		i++;
	}
	i = 1;
	while (i <= size)
	{
		output[counter[(((*array)[size - i] / ft_10power(exp_cur)) % 10) + 9]] = (*array)[size - i];
		counter[(((*array)[size - i] / ft_10power(exp_cur)) % 10) + 9]--;
		i++;
	}

	i = 0;
	while (i < size)
	{
		printf("%i\n", output[i]);
		i++;
	}


	// i = -1;
	// printf("Start of the counter\n");
	// while (++i < 19)
	// 	printf("%i\n", counter[i]);
	// printf("End of the counter\n");
}