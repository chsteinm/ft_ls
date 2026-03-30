/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:22:17 by chrstein          #+#    #+#             */
/*   Updated: 2024/04/18 20:41:17 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsdup(char **strs, size_t size)
{
	char	**ret;
	size_t	i;

	ret = ft_calloc((size + 1), sizeof(char *));
	if (!ret)
		return (NULL);
	i = -1;
	while (strs[++i])
	{
		ret[i] = ft_strdup(strs[i]);
		if (!ret[i])
			return (ft_free_strings(ret), NULL);
	}
	return (ret);
}
