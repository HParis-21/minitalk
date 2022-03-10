#include "minitalk.h"

void	sig_hand(int signal, siginfo_t *info, void *ucontext)
{
	static int		count = 128;
	static char		c = 0;

	(void)*ucontext;
	if (signal == SIGUSR1)
	{
		c += count;
		count >>= 1;
	}
	else if (signal == SIGUSR2)
		count >>= 1;
	if (count == 0)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		count = 128;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &sig_hand;
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		usleep(10);
	}
}
