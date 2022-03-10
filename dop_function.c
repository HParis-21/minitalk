#include "minitalk.h"

static int	ft_number(const char *s, int i, int z)
{
	long long	res;

	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i++] - '0');
		if (res > 2147483647 && (z == 1))
			return (-1);
		if (res > 2147483648 && (z == -1))
			return (0);
	}
	return ((int)(res * z));
}

int	ft_atoi(const char *s)
{
	int	i;
	int	z;
	int	res;

	i = 0;
	z = 1;
	res = 0;
	while (s[i] == '\t' || s[i] == '\v' || s[i] == '\f' || s[i] == '\r' \
			 || s[i] == '\n' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		z = ',' - s[i++];
	res = ft_number(s, i, z);
	return (res);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * (-1);
		write(fd, "-", 1);
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	c = '0' + (nb % 10);
	write(fd, &c, 1);
}
