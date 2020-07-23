/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:15:23 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/21 20:57:46 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_check_base(char *base);

int		ft_strlength(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int		ft_at(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != c && base[i])
		i++;
	if (i >= ft_strlength(base))
		return (-1);
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int		size;
	int		i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (!ft_check_base(base))
		return (0);
	size = ft_strlength(base);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_at(str[i], base) >= 0)
	{
		res = res * size + ft_at(str[i], base);
		i++;
	}
	return (sign * res);
}
