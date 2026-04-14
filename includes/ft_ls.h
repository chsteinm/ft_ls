/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 23:48:32 by chrstein          #+#    #+#             */
/*   Updated: 2026/04/10 23:48:34 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

# define INVLD_OPTS "ft_ls: invalid option -- '%c'\n\
Try to read the f... subject for more information.\n"
# define CNTACSS "ft_ls: cannot access '%s': %s\n"

typedef struct s_data
{
	// bool isOptions;
	int		nb_args;
	bool	l;
	bool	R;
	bool	a;
	bool	r;
	bool	t;
	t_list	*files;
}					t_data;

void init_options(t_data *data, char **argv);

#endif
