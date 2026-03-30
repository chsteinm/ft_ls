#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>

# define MUST_EXIT 242

# define ERR_DENIED "%s: Permission denied\n"
# define ERR_IS_FILE "%s: Is a directory\n"
# define ERR_EXIT "exit: too many arguments\n"
# define ERR_EXIT_N "exit: %s: numeric argument required\n"
# define ERR_CD "cd: %s: No such file or directory\n"
# define ERR_CD_TMA "cd: too many arguments\n"

typedef struct s_data
{
	t_list	*cmd_param;
	t_list	*cmds;
	t_list	*var_no_value;
	char	**env;
	char	**path;
	char	*pwd;
	char	*line;
	char	*no_space_line;
	int		last_status;
	pid_t	pid;
	char	*tmp;
	char	*to_free;
	int		nb_line_hd;
	size_t	nb_cmds;
	size_t	i;
	bool	cancel;
}					t_data;


#endif
