#include "../includes/libft.h"

int	is_number(char *num)
{
	while (*num)
	{
		if (*num < '0' || *num > '9')
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
		if (!is_number(argv[argc]))
		{
			return (NULL);
			free(temp);
		}
		temp[argc - 1] = ft_atoi(argv[argc]);
	}
	return (temp);
}

int main(int argc, char *argv[])
{
	int	*s_a;
	int	i;

	i = 0;
	s_a = data_loader(argc, argv);
	if (!s_a)
	{
		ft_putstr_fd("Error importing the array\n", 2);
		return (1);
	}
	
	while (i < argc - 1)
	{
		printf("%i\n",s_a[i]);
		i++;
	}
	
	return 0;
}
