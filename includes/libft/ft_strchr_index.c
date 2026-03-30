/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:19 by chrstein          #+#    #+#             */
/*   Updated: 2024/04/18 15:14:23 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_index(char *s, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		if (s[i] == *to_find)
		{
			j = 0;
			while (to_find[j] && s[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (i);
		}
		i++;
	}
	return (0);
}
