/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:40:11 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/22 11:24:02 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		*tab;
	int		len;
	int		i;

	len = (max - min);
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(*tab) * (len));
	if (tab == NULL)
	{
		return (-1);
	}
	while (i < len)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (len);
}
