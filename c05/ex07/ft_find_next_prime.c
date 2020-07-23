/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 10:48:20 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/20 16:45:41 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2 || nb > 2147483647)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (nb == 2147483647)
		return (nb);
	if (nb > 2147483647)
		return (0);
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}

int main()
{
	printf("%d\n", ft_find_next_prime(49994));
}
