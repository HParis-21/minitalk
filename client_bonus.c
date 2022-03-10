#include "minitalk.h"

void	count_bit(char c, int pid)
{
	int	count;

	count = 128;
	while (count != 0)
	{
		if (count & c)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Failed signing!\n", 16);
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Failed signing!\n", 16);
				exit(0);
			}
		}
		count >>= 1;
		usleep(100);
	}
}

void	sighander(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message has been sent!\n", 23);
	exit(1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = -1;
	if (argc != 3)
	{
		write(2, "Invalid numbers of arguments!\n", 31);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		write(2, "PID-number not valid!\n", 22);
		return (1);
	}
	else
	{
		signal(SIGUSR1, sighander);
		while (argv[2][++i])
			count_bit(argv[2][i], pid);
		count_bit('\n', pid);
		count_bit('\0', pid);
	}
	return (0);
}
