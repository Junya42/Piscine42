/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:51:25 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/21 19:11:33 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		count;

	count = 0;
	if (min >= max)
		return (0);
	tab = malloc(sizeof(int) * (max - min + 1));
	if (tab == 0)
		return (0);
	while (min < max)
	{
		tab[count] = min;
		count++;
		min++;
	}
	tab[count] = '\0';
	return (tab);
}
