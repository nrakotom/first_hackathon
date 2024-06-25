
#include "../includes/libft.h"

void	ft_putchar(char c)
{
	ssize_t	i;

	i = write(1, &c, 1);
	if (i == -1)
		return ;
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar('-');
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putchar((n % 10) + 48);
		}
		else
			ft_putchar((n + 48));
	}
}
