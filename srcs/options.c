/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 23:55:17 by chrstein          #+#    #+#             */
/*   Updated: 2026/04/10 23:55:19 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	print_options(t_data *data)
{
	ft_dprintf(2, "Options : -");
	if (data->l)
		ft_dprintf(2, "l");
	if (data->R)
		ft_dprintf(2, "R");
	if (data->a)
		ft_dprintf(2, "a");
	if (data->r)
		ft_dprintf(2, "r");
	if (data->t)
		ft_dprintf(2, "t");
	ft_dprintf(2, "\n");
}

void	set_option(t_data *data, char c)
{
	if (c == 'l')
		data->l = true;
	else if (c == 'R')
		data->R = true;
	else if (c == 'a')
		data->a = true;
	else if (c == 'r')
		data->r = true;
	else if (c == 't')
		data->t = true;
	else if (c != '-')
	{
		ft_dprintf(2, INVLD_OPTS, c);
		exit(2);
	}
}

void	init_options(t_data *data, char **argv)
{
	int		i;
	char	*c;

	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '-')
		{
			c = argv[i] + 1;
			while (*c)
				set_option(data, *c++);
		}
	}
	if (DEBUG)
		print_options(data);
}
