/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 11:30:51 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/21 20:58:27 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_test(char *tab, char **strs, char *sep, int size)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			tab[k] = strs[i][j++];
			k++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			tab[k] = sep[j];
			k++;
			j++;
		}
		i++;
	}
	tab[k] = '\0';
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		k;
	int		i;
	int		j;
	char	*tab;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			k++;
		}
		j = 0;
		while (sep[j])
		{
			k++;
			j++;
		}
		i++;
	}
	tab = malloc(sizeof(char) * (k + 1));
	return (ft_test(tab, strs, sep, size));
}
