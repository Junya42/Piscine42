/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:16:33 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/22 16:47:03 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_occur(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		ft_get_size(char *str, char *charset)
{
	int		size;

	size = 0;
	while (*str)
	{
		if (ft_occur(*str, charset) == 0)
		{
			size++;
			while (*str && ft_occur(*str, charset) == 0)
				str++;
		}
		str++;
	}
	return (size);
}

void	ft_strcpy(char *dst, char *copy, char *until)
{
	while (copy < until)
		*(dst++) = *(copy++);
	*dst = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**copy;
	int		i;
	char	*from;

	i = 0;
	copy = ((char**)malloc(sizeof(char*) * (ft_get_size(str, charset) + 1)));
	if (!str && !charset)
	{
		copy[0] = 0;
		return (copy);
	}
	while (*str)
	{
		if (ft_occur(*str, charset) == 0)
		{
			from = str;
			while (*str && ft_occur(*str, charset) == 0)
				str++;
			copy[i] = (char*)malloc(str - from + 1);
			ft_strcpy(copy[i++], from, str);
		}
		str++;
	}
	copy[i] = 0;
	return (copy);
}
