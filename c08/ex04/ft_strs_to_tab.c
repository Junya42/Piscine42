/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:52:17 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/21 16:37:22 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int								ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char							*ft_strdup(char *src)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct	s_stock_str				*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*stock;
	int				i;

	stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (stock == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}
