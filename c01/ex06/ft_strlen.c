/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:28:04 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/05 19:11:55 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int main()
{
	char tab[]="hello world";
	int nb = 0;

	ft_strlen(tab);
	printf("%d", nb);
	return 0;
}
