/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:04:09 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/13 14:12:48 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		nb;

	nb = 0;
	while (*(str++))
	{
		nb++;
	}
	return (nb);
}

void	convertor_base(char *str, int *nbr)
{
	int				a;
	int				b;
	int 			strlenbase;

	strlenbase = ft_strlen(*str);
	a = (*nbr / *strlenbase) % *strlenbase;
	b = *nbr % *strlenbase;
	ft_putchar(str[a]);
	ft_putchar(str[b]);
}
