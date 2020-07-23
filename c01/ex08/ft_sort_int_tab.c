/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:32:35 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/04 19:34:37 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		tmp;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] >= tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			i++;
		}
		j++;
	}
}
