#include <stdio.h>

static int	verify_base_nbr(char c, char *base)
{
	int j;

	j = 0;
	while (base[j])
		j++;
	j = j - 1;
	if (j <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + j - 10)) || \
	(c >= 'a' && c <= ('a' + j - 10)));
}

int			ft_atoi_base(char *str, char *base)
{
	int		i;
	int		nbr;
	int		sign;
	int		j;

	j = 0;
	while (base[i])
		j++;
	if (!str || (j < 2 || j > 16))
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || \
		str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		str[i++] == '-' ? sign *= -1 : sign;
	while (str[i] && verify_base_nbr(str[i], base))
	{
		if (str[i] >= 'A' && 'F' >= str[i])
			nbr = (nbr * j) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && 'f' >= str[i])
			nbr = (nbr * j) + (str[i] - 'a' + 10);
		else
			nbr = (nbr * j) + (str[i] - '0');
		i += 1;
	}
	return (nbr * sign);
}

#include <stdio.h>

int main()
{
	printf("%d\n", ft_atoi_base("42", "01"));
	return 0;
}
