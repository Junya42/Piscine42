/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:26:57 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/16 19:50:04 by aremiki          ###   ########.fr       */
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

void	ft_rev_int_tab(int *tab, int size)
{
	int		tmp;
	int		i;
	int		j;

	i = 0;
	j = size - 1;
	while (i < (size / 2))
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	strlen_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	strlen_base = 0;
	if (check_base(base))
	{
		while (base[strlen_base])
			strlen_base++;
		while (nbr)
		{
			nbr_final[i] = (nbr / strlen_base) % strlen_base;
			i++;
			nbr_final[i] = nbr % strlen_base;
			i++;
		}
	}
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
	int		atoi;
	int		lenbase;
	int		*res;
	int		a;

	lenbase = ft_strlen(base);
	i = 0;
	j = 1;
	atoi = 0;
	res[a] = 0;
	if (check_base(base))
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				j = -j;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			atoi = atoi * lenbase + (str[i] - 48);
			i++;
		}
		while (atoi > 0)
		{
			res[a] = atoi % lenbase;
			atoi = atoi / lenbase;
		}
		return (res * j);
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
