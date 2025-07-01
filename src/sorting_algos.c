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
		if (ft_abs(array[i]) > ft_abs(array[max]))
			max = i;
	}
	digits = 0;
	while (ft_abs(array[max]) / ft_10power(digits) > 9)
		digits++;
	return (digits);
}

void	prefix_sum_sort(int **array, int size, int *output, int exp_max)
{
	int	c[19];
	int	i;
	int	exp_cur;

	exp_cur = 0;
	while (exp_cur <= exp_max)
	{
		i = -1;
		while (++i < 19)
			c[i] = 0;
		i = -1;
		while (++i < size)
			c[(((*array)[i] / ft_10power(exp_cur)) % 10) + 9]++;
		i = 0;
		while (++i < 19)
			c[i] += c[i - 1];
		i = -1;
		while (++i < 19)
			c[i]--;
		i = 1;
		while (i <= size)
		{
			output[c[(((*array)[size - i] / ft_10power(exp_cur)) % 10) + 9]] = (*array)[size - i];
			c[(((*array)[size - i] / ft_10power(exp_cur)) % 10) + 9]--;
			i++;
		}
		i = 0;
		while (i < size)
		{
			(*array)[i] = output[i];
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
