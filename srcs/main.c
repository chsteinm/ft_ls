/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:38:52 by chrstein          #+#    #+#             */
/*   Updated: 2026/04/10 16:38:54 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	clean_exit(t_data *data, char *error)
{
	(void)data;
	if (error)
		ft_dprintf(2, "%s\n", error);
	exit(EXIT_FAILURE);
}

void	push_file(t_data *data, char *file)
{
	t_list *new = ft_lstnew(file);
	if (!new)
		clean_exit(data, "ft_ls: push_file: Malloc Fail");
	if (lstat(file, &new->sta) == -1)
		clean_exit(data, strerror(errno));
	
}

void	parse(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->nb_args = 0;
	while (argv[++i])
	{
		if (DEBUG)
			ft_dprintf(2, "arg: %s\n", argv[i]);
		if (argv[i][0] != '-' || (argv[i][0] == '-' && !argv[i][1]))
		{
			DIR *dirp = opendir(argv[i]);
			if (!dirp)
			{
				if (DEBUG)
					ft_dprintf(2, "errno: %d\n", errno);
				if (errno != 20)
					ft_dprintf(2, CNTACSS, argv[i], strerror(errno));
				else
					push_file(data, argv[i]);
				continue;
			}
			data->nb_args++;

		}
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, argc - argc, sizeof(t_data));
	init_options(&data, argv);
	parse(&data, argv);
	return (EXIT_SUCCESS);
}
