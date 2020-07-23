/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:24:41 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/05 11:29:43 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char nbr1;
	char nbr2;
	char nbr3;

	nbr1 = '0';
	while (nbr1 <= '7')
	{
		nbr2 = nbr1 + 1;
		while (nbr2 <= '8')
		{
			nbr3 = nbr2 + 1;
			while (nbr3++ <= '9')
			{
				ft_putchar(nbr1);
				ft_putchar(nbr2);
				ft_putchar(nbr3 - 1);
				if (!(nbr1 == '7' && nbr2 == '8' && (nbr3 - 1) == '9'))
				{
					write(1, ", ", 2);
				}
			}
			nbr2++;
		}
		nbr1++;
	}
}

int main()
{
	ft_print_comb();
	return 0;
}
