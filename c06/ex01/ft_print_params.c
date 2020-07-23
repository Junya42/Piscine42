/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:26:04 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/20 10:00:51 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*(str++))
	{
		write(1, str - 1, 1);
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc > 1)
		while (argv[i])
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	return (0);
}
