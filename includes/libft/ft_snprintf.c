#include "libft.h"

int	print_c_buf(va_list args, char *buf, size_t *size)
{
	// ft_putchar_buf(va_arg(args, int), buf);
	*buf = va_arg(args, int);
	*size -= 1;
	return (1);
}

int	print_convert_buf(va_list args, const char *str, char *buf, size_t *size)
{
	if (*str == 'c')
		return (print_c_buf(args, buf, size));
	else if (*str == 's')
		return (print_str_buf(args, buf, size));
	else if (*str == 'd' || *str == 'u' || *str == 'i')
		return (print_n_base10_buf(args, *str, buf, size));
	else
		{
			*buf = *str;
			*size -= 1;
			return (1);
		}
}

int	print_printable_buf(const char *str, char *buf, size_t *size)
{
	int	i;

	i = -1;
	while (str[++i] != '%' && str[i] && *size > 0)
	{
		buf[i] = str[i];
		*size -= 1;
	}
	return (i);
}

int	print_buf(va_list args, const char *str, char *buf, size_t size)
{
	int	count_printed_char;
	int	i;
	int	check;

	count_printed_char = 0;
	while (*str && size > 1)
	{
		if (*str == '%')
		{
			check = print_convert_buf(args, str + 1, buf, &size);
			if (check == -1)
				return (-1);
			count_printed_char += check;
			str += 2;
			buf += check;
		}
		i = print_printable_buf(str, buf, &size);
		if (i == -1)
			return (-1);
		count_printed_char += i;
		str += i;
		buf += i;
	}
	*buf = 0;
	return (count_printed_char);
}
/*return size if the output was truncated, -1 if size == 0*/
int	ft_snprintf(char *buf, size_t size, const char *str, ...)
{
	va_list	args;
	int		count_printed_char;

	if (!str || !size || !buf)
		return (-1);
	if (!(*str))
	{
		*buf = 0;
		return (0);
	}
	count_printed_char = 0;
	va_start(args, str);
	count_printed_char = print_buf(args, str, buf, size - 1);
	va_end(args);
	return (count_printed_char);
}
