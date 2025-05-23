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
	int	max;
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
	while (ABS(array[max]) / ft_10power(digits) > 9)
		digits++;
	return (digits);
}

void	prefix_sum_sort(int **array, int size, int *output, int exp_max)
{
	int	counter[19];
	int	i;
	int	exp_cur;

	exp_cur = 0;
	while (exp_cur <= exp_max)
	{
		i = -1;
		while (++i < 19)
			counter[i] = 0;
		i = -1;
		while (++i < size)
			counter[(((*array)[i] / ft_10power(exp_cur)) % 10) + 9]++;
		i = 0;
		while (++i < 19)
			counter[i] += counter[i - 1];
		i = -1;
		while (++i < 19)
			counter[i]--;
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
			(*array)[i] =  output[i];
			i++;
		}
		exp_cur++;
	}
}

void	radix_sort(int **array, int size)
{
	int	*output;
	int	exp_max;

	output = malloc(sizeof(int) * size);
	if (!output)
		exit (1);
	exp_max = find_max(*array, size);
	prefix_sum_sort(array, size, output, exp_max);
}