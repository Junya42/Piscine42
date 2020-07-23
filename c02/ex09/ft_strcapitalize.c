/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:46:46 by aremiki           #+#    #+#             */
/*   Updated: 2020/07/08 17:44:41 by aremiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alpha(char str)
{
	if ('a' <= str && str <= 'z')
		return (1);
	else if ('A' <= str && str <= 'Z')
		return (1);
	else if ('0' <= str && str <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*ptr;

	ptr = str;
	if (ft_is_alpha(*str))
	{
		if (('a' <= *str && *str <= 'z'))
			*str -= ('a' - 'A');
	}
	while (*str++)
	{
		if (ft_is_alpha(*str) == 1)
		{
			if ('A' <= *str && *str <= 'Z')
				*str += ('a' - 'A');
			if (!ft_is_alpha(*(str - 1)))
			{
				if ('a' <= *str && *str <= 'z')
					*str -= ('a' - 'A');
			}
		}
	}
	return (ptr);
}
