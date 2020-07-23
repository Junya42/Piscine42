/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:26:57 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/16 20:52:48 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int		*ft_putnbr_base(int nbr, char *base)
{
	int	strlen_base;
	int	*nbr_final;
	int	i;

	i = 0;
	strlen_base = 0;
	if (check_base(base))
	{
		while (base[strlen_base])
			strlen_base++;
		while (nbr != 0)
		{
			nbr_final[i] = (nbr / strlen_base) % strlen_base;
			nbr_final[i + 1] = nbr % strlen_base;
			i++;
		}
	}
	return (nbr_final);
}

int		ft_strlen(char *base)
{
	int i;

	i = 0;
	while(base[i])
		i++;
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	int		atoied;
	int		lenbase;
	int		*res;
	int		a;

	lenbase = ft_strlen(base);
	i = 0;
	j = 0;
	atoied = 0;
	if (check_base(base))
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				j++;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			atoied = atoied * lenbase + (str[i] - 48);
			i++;
		}
		if (atoied > 0)
			*res = *ft_putnbr_base(atoied, base);
		if (j % 2 == 1)
		{
			write(1, "-", 1);
			return (*res);
		}
		else
			return (*res);
	}
	else
		return (0);
}

int main()
{
	char str[] = "94";
	char base[] = "01";
	printf("%d",ft_atoi_base(str,base));
	return (0);
}
