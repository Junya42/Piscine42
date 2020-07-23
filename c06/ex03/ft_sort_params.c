/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 13:16:02 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/20 10:01:42 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_params(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_sort_params(int argc, char **argv, int i, int c)
{
	int		nb;
	char	*temp;

	nb = 0;
	while (nb <= argc)
	{
		while (argv[i])
		{
			while (argv[c])
			{
				if (ft_strcmp(argv[i], argv[c]) < 0)
				{
					temp = argv[i];
					argv[i] = argv[c];
					argv[c] = temp;
				}
				c++;
			}
			i++;
			c = 1;
		}
		nb++;
		i = 1;
	}
}

int		main(int argc, char **argv)
{
	int		j;
	int		i;
	int		c;

	i = 1;
	c = 2;
	j = 1;
	if (argc <= 1)
		return (0);
	ft_sort_params(argc, argv, i, c);
	while (argv[j])
	{
		ft_print_params(argv[j]);
		j++;
	}
	return (0);
}
