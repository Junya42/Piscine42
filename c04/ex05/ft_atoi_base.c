/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:11:27 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/18 16:35:11 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int nb;

	nb = 0;
	while (*(str++))
		nb++;
	return (nb);
}

char	check_char(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	int		atoi;
	int		len;

	i = 0;
	j = 1;
	atoi = 0;
	len = ft_strlen(base);
	if (check_base(base) == 1)
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				j = -j;
			i++;
		}
		while (str[i])
			atoi = atoi * len + (check_char(str[i++], base));
		return (atoi * j);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d\n", ft_atoi_base(argv[1], argv[2]));
	return (0);
}
