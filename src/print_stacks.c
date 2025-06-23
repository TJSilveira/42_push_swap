#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	print_stacks(t_s *s_a, t_s *s_b, int size)
{
	int	counter_a;
	int	counter_b;

	counter_a = 0;
	counter_b = 0;
	ft_putstr_fd("Current Stacks\nA:\tB:\n", 1);
	while ((counter_a + counter_b) < size)
	{
		if (s_a == NULL || (s_a->start && counter_a != 0))
			ft_putchar_fd(' ', 1);
		else
		{
			ft_putnbr_fd(s_a->num, 1);
			s_a = s_a->next;
			counter_a++;
		}
		ft_putchar_fd('\t', 1);
		if (s_b == NULL || (s_b->start && counter_b != 0))
			ft_putchar_fd(' ', 1);
		else
		{
			ft_putnbr_fd(s_b->num, 1);
			s_b = s_b->next;
			counter_b++;
		}
		ft_putchar_fd('\n', 1);
	}
}
