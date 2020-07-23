/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:08:03 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/14 21:06:15 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		i;
	int		nbcpy;

	i = 1;
	nbcpy = nb;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	else
		while (i < nb)
		{
			nbcpy = nbcpy * i;
			i++;
		}
	return (nbcpy);
}
