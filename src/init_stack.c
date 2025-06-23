#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_stacks	*init_stack(int argc, char *argv[])
{
	int	*arr_a;
	t_s	*s_a;
	t_s	*s_b;

	arr_a = data_loader(argc, argv);
	if (!arr_a)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	indexator(arr_a, argc - 1);
	s_a = stack_loader(arr_a, argc - 1);
	s_b = NULL;
	free(arr_a);
	return(list_loader(s_a, s_b));
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

int	*data_loader(int argc, char *argv[])
{
	int *temp;

	temp = malloc(sizeof(int) * (argc - 1));
	while (--argc > 0)
	{
		if (!is_int(argv[argc]))
		{
			free(temp);
			return (NULL);
		}
		temp[argc - 1] = ft_atoi(argv[argc]);
	}
	return (temp);
}

void	check_repeated(int* array, int size)
{
	int i;
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
				exit(1);
			}
			j++;
		}
	}
}