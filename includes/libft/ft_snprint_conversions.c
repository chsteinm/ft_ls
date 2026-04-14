#include "libft.h"

/*the number of bytes written is returned*/
int	ft_putnstr_buf(char *src, char *buf, size_t *size)
{
	int	i;

	i = -1;
	while (src[++i] && *size > 1)
	{
		buf[i] = src[i];
		*size -= 1;
	}
	return (i);
}

int	print_str_buf(va_list args, char *buf, size_t *size)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		return (ft_putnstr_buf("(null)", buf, size));
	}
	return (ft_putnstr_buf(str, buf, size));
}

int	print_n_base10_buf(va_list args, char c, char *buf, size_t *size)
{
	int		i;
	char	*str;

	if (c == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	else
		str = ft_itoa(va_arg(args, int));
	if (!str)
		return (0);
	i = ft_putnstr_buf(str, buf, size);
	free(str);
	return (i);
}
