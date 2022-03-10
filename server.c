#include "minitalk.h"

void	sig_hand(int signal)
{
	static int		count = 128;
	static char		c = 0;

	if (signal == SIGUSR1)
	{
		c += count;
		count >>= 1;
	}
	else if (signal == SIGUSR2)
		count >>= 1;
	if (count == 0)
	{
		write(1, &c, 1);
		count = 128;
		c = 0;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_hand);
	signal(SIGUSR2, sig_hand);
	while (1)
		usleep(100);
}
