/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:15:57 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/21 19:15:59 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_atoi_base(char *str, char *base);
int		ft_at(char c, char *base);
int		ft_strlength(char *str);
int		ft_isspace(char c);

int		ft_check_base(char *base)
{
	int				i;
	int				z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (ft_isspace(base[i]))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int		ft_wordcount(int nbr, char *base)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr = nbr - (nbr % ft_strlength(base));
		nbr = nbr / ft_strlength(base);
		i++;
	}
	return (i);
}

void	ft_nbr_base(int nbr, char *res, char *base, int *last)
{
	int		size;

	size = ft_strlength(base);
	if (nbr == -2147483648)
	{
		res[0] = '-';
		(*last)++;
		ft_nbr_base((-(long int)nbr) / size, res, base, last);
		ft_nbr_base((-(long int)nbr) % size, res, base, last);
	}
	else if (nbr < 0)
	{
		res[0] = '-';
		(*last)++;
		ft_nbr_base(-nbr, res, base, last);
	}
	else if (nbr < size)
		res[(*last)++] = base[nbr];
	else
	{
		ft_nbr_base(nbr / size, res, base, last);
		ft_nbr_base((nbr) % size, res, base, last);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res_str;
	int		nb;
	int		last;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	res_str = malloc(sizeof(char) * (ft_wordcount(nb, base_to) + 1));
	last = 0;
	ft_nbr_base(nb, res_str, base_to, &last);
	res_str[ft_wordcount(nb, base_to)] = '\0';
	return (res_str);
}
