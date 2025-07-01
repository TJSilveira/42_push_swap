#include "../includes/push_swap.h"

t_stacks	*init_stack(int argc, char *argv[])
{
	int		*arr_a;
	char	**temp;
	int		count_num;
	t_s		*s_a;
	t_s		*s_b;


	if (argc == 2 && argv[1][0])
	{
		temp = ft_split(argv[1], ' ');
		if (!temp)
			exit(1);
		count_num = 0;
		while (temp[count_num])
			count_num++;
		arr_a = data_loader(count_num, temp);
		free_arrays(temp);
	}
	else
	{
		count_num = argc - 1;
		arr_a = data_loader(count_num, &argv[1]);
	}
	if (!arr_a)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	indexator(arr_a, count_num);
	s_a = stack_loader(arr_a, count_num);
	s_b = NULL;
	free(arr_a);
	return (list_loader(s_a, s_b));
}

int	is_int(char *num)
{
	long int	final_num;
	int			s;

	final_num = 0;
	s = 0;
	if (*num == 0)
		return (0);
	if (*num == '-')
	{
		if (ft_strlen(num) == 1)
			return (0);
		s++;
		num++;
	}
	while (*num)
	{
		if (!(*num >= '0' && *num <= '9'))
			return (0);
		final_num = final_num * 10 + *num - '0';
		if ((final_num > 2147483648 && s) || (final_num > INT_MAX && !s))
			return (0);
		num++;
	}
	return (1);
}

int	*data_loader(int count_num, char *argv[])
{
	int	*temp;

	temp = malloc(sizeof(int) * (count_num));
	while (--count_num >= 0)
	{
		if (!is_int(argv[count_num]))
		{
			free(temp);
			return (NULL);
		}
		temp[count_num] = ft_atoi(argv[count_num]);
	}
	return (temp);
}

void	check_repeated(int *array, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				ft_putstr_fd("Error\n", 2);
				free(array);
				exit(1);
			}
			j++;
		}
	}
}

void	free_arrays(char **arrays)
{
	int	i;

	i = 0;
	while (arrays[i])
	{
		free(arrays[i]);
		i++;
	}
	free(arrays);
}
