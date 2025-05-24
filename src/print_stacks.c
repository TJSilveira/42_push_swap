#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	print_stacks(t_s *s_a, t_s *s_b, int size)
{
	int	counter[2];

	counter[0] = 0;
	counter[1] = 0;
	while ((counter[0] + counter[1]) < size)
	{
		if (s_a == NULL || (s_a->start && counter[0] != 0))
			ft_putchar_fd(' ', 1);
		else
		{
			ft_putnbr_fd(s_a->num, 1);
			s_a = s_a->next;
			counter[0]++;
		}
		ft_putchar_fd('\t', 1);
		if (s_b == NULL || (s_b->start && counter[1] != 0))
			ft_putchar_fd(' ', 1);
		else
		{
			ft_putnbr_fd(s_b->num, 1);
			s_b = s_b->next;
			counter[1]++;
		}
		ft_putchar_fd('\n', 1);
	}
}
