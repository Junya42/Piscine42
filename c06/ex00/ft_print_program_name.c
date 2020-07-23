/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:19:30 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/20 09:59:43 by aremiki          ###   ########.fr       */
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
	if (argc >= 0)
		ft_putstr(argv[0]);
	write(1, "\n", 1);
	return (0);
}
