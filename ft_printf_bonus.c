#include "ft_printf.h"

int	ft_printf_width(char *str, char sym, int width)
{
	int		count;
	int		len;

	count = -1;
	len = ft_strlen(str);
	if (!len)
		len = 6;
	while (width > len + (++count))
		ft_putchar_fd(sym, 1);
	count += ft_putstr_fd(str, 1);
	return (count);
}

int	ft_printf_leftwidth(char *str, int width)
{
	int		count;

	count = -1;
	count += ft_putstr_fd(str, 1);
	while (width > ++count)
		ft_putchar_fd(' ', 1);
	return (count);
}

char	*ft_precision_i(char *n, int width)
{
	char	*str;

	while (width > (int)ft_strlen(n))
	{
		str = ft_strjoin("0", n);
		free(n);
		n = str;
	}
	return (n);
}

long int	ft_abs(int nbr)
{
	long int	n;

	n = nbr;
	if (n < 0)
		return (n * (-1));
	return (n);
}

int	ft_printchrit(char c, int t)
{
	int		i;

	i = 0;
	while (t-- > 0)
		i += ft_putchar_fd(c, 1);
	return (i);
}

int	ft_printf_i(int nbr, t_lis *list)
{
	char	*n;
	//char	*str;
	int		i;

	i = 0;
	n = ft_itoa(ft_abs(nbr));
	if (list->pwidth > (int)ft_strlen(n))
		n = ft_precision_i(n, list->pwidth);
	else if (nbr == 0 && list->pwidth == 0 && list->precision == 1)
		n[0] = '\0';
	if ((!ft_strchr(list->flags, '-') && !ft_strchr(list->flags, '0'))
		|| (list->precision && ft_strchr(list->flags, '0')))
	{
		if (nbr >= 0)
			i = ft_printchrit(' ', list->width - ft_strlen(n) -
			ft_strchr(list->flags, '+') - ft_strchr(list->flags, ' '));
		else
			i = ft_printchrit(' ', list->width - ft_strlen(n) -
			1 - ft_strchr(list->flags, ' '));

	}
	if (ft_strchr(list->flags, ' ') && !ft_strchr(list->flags, '+') && nbr >= 0)
		i += ft_putchar_fd(' ', 1);
	if (nbr < 0)
		i += ft_putchar_fd('-', 1);
	else if (nbr >= 0 && ft_strchr(list->flags, '+'))
		i += ft_putchar_fd('+', 1);
	if (ft_strchr(list->flags, '0') && !list->precision)
		i += ft_printchrit('0', list->width - i - ft_strlen(n));
	i += ft_putstr_fd(n, 1);
	if (ft_strchr(list->flags, '-'))
		i += ft_printchrit(' ', list->width - i);
	free(n);
	return (i);
	

	/*if (ft_strchr(list->flags, '+') && nbr >= 0)
	{
		str = ft_strjoin("+", n);
		free(n);
	}
	else if (!ft_strchr (list->flags, '+') && nbr >= 0 && ft_strchr(list->flags, ' '))
	{
		str = ft_strjoin(" ", n);
		free(n);
	}
	else
		str = n;
	if (ft_strchr(list->flags, '0') && list->width > (int)ft_strlen(str))
		i = ft_printf_width(str, '0', list->width);
	else if (ft_strchr(list->flags, '-') && list->width > (int)ft_strlen(str))
		i = ft_printf_leftwidth(str, list->width);
	else if (list->width > (int)ft_strlen(str))
		i = ft_printf_width(str, ' ', list->width);
	else if (list->width <= (int)ft_strlen(str))
		i = ft_putstr_fd(str, 1);
	free(str);
	return (i);*/
}

int	ft_printf_s(char *str, t_lis *list)
{
	int		len;
	int		i;
	int		j;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	i = 0;
	j = 0;
	if (!ft_strchr(list->flags, '-') && list->width > len)
		i += ft_printchrit(' ', list->width - len);
	while ((!list->precision && str[j]) || (list->precision && list->pwidth > j && str[j]))
		write(1, &str[j++], 1);
	if (ft_strchr(list->flags, '-') && list->width > i + j)
		i += ft_printchrit(' ', list->width - i - j);
	return (i + j);
}

char	*ft_utos(unsigned int n)
{
	char	*reverse;
	char	*str;
	int		i;

	i = 0;
	reverse = (char *)malloc(sizeof(char) * 11);
	if (!reverse)
		return (0);
	if (!n)
	{
		reverse[0] = '0';
		reverse[1] = '\0';
		return (reverse);
	}
	while (n != 0)
	{
		reverse[i++] = (n % 10) + 48;
		n = n / 10;
	}
	str = (char *)malloc(sizeof(char) * 11);
	if (!str)
		return (0);
	while (--i >= 0)
		str[n++] = reverse[i];
	str[n] = '\0';
	free(reverse);
	return (str);
}

int	ft_printf_u(unsigned int nbr, t_lis *list)
{
	char	*str;
	int		i;

	str = ft_utos(nbr);
	if (list->pwidth > (int)ft_strlen(str))
		str = ft_precision_i(str, list->pwidth);
	if (nbr == 0 && list->pwidth == 0 && list->precision == 1)
		str[0] = '\0';
	if (ft_strchr(list->flags, '0') && !list->precision)
		str = ft_precision_i(str, list->width);
	list->precision = 0;
	list->pwidth = 0;
	i = ft_printf_s(str, list);
	free(str);
	return (i);
}

char	*ft_hex(unsigned long int nbr, char sym, int i)
{
	char	*hex;
	char	*base;
	char	*str;

	hex = (char *)malloc(sizeof(char) * 20);
	if (!hex)
		return (0);
	if (!nbr)
	{
		hex[0] = '0';
		hex[1] = '\0';
		return (hex);
	}
	base = "0123456789abcdef";
	if (sym == 'X')
		base = "0123456789ABCDEF";
	while (nbr)
	{
		hex[++i] = base[nbr % 16];
		nbr = nbr / 16;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
	{
		free(hex);
		return (0);
	}
	while (i >= 0)
		str[nbr++] = hex[i--];
	str[nbr] = '\0';
	free(hex);
	return (str);
}

int	ft_printf_x(unsigned long int nbr, char sym, t_lis *list)
{
	int		i;
	char	*str;

	i = 0;
	//if (!nbr)
	//	str = "0";                          //&&&&?????????????
	str = ft_hex(nbr, sym, -1);
	if ((int)ft_strlen(str) < list->pwidth)
		str = ft_precision_i(str, list->pwidth);
	if (nbr == 0 && list->pwidth == 0 && list->precision == 1)
		str[0] = '\0';
	if ((!ft_strchr(list->flags, '-') && !ft_strchr(list->flags, '0'))
		|| ((list->precision || !ft_strlen(str)) && ft_strchr(list->flags, '0')))
		i += ft_printchrit(' ', list->width - ft_strlen(str) - 2 * (ft_strchr(list->flags, '#')));
	if (ft_strchr(list->flags, '#') && nbr)
	{
		if (sym == 'x')
			i += ft_putstr_fd("0x", 1);
		else
			i += ft_putstr_fd("0X", 1);
	}
	if (ft_strchr(list->flags, '0') && ft_strlen(str) && !list->precision)
		i += ft_printchrit('0', list->width - ft_strlen(str) - i);
	i += ft_putstr_fd(str, 1);
	if (ft_strchr(list->flags, '-'))
		i += ft_printchrit(' ', list->width - i);
	free(str);
	return (i);
	/*if (ft_strchr(list->flags, '0') && list->width > (int)ft_strlen(str))
		i += ft_printf_width(str, '0', list->width);
	else if (ft_strchr(list->flags, '-') && list->width > (int)ft_strlen(str))
		i += ft_printf_leftwidth(str, list->width);
	else if (list->width > (int)ft_strlen(str))
		i += ft_printf_width(str, ' ', list->width);
	else if (list->width <= (int)ft_strlen(str))
		i += ft_putstr_fd(str, 1);
	free(str);
	return (i);*/
}

int	ft_putxstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
	{
		write(fd, "0", 1);
		return (1);
	}
	len = ft_strlen(s);
	if (fd != -1)
		write(fd, s, len);
	return (len);
}

int	ft_printf_p(unsigned long int nbr, t_lis *list)
{
	int		i;
	char	*str;
	char	*n;

	n = ft_hex(nbr, 'x', -1);
	str = ft_strjoin("0x", n);
	free(n);
	if (ft_strchr(list->flags, '-') && list->width > (int)ft_strlen(str))
		i = ft_printf_leftwidth(str, list->width);
	else if (list->width > (int)ft_strlen(str))
		i = ft_printf_width(str, ' ', list->width);
	else if (list->width<= (int)ft_strlen(str))
		i = ft_putxstr_fd(str, 1);
	free(str);
	return (i);
}

int	ft_printf_c(char c, char *flags, int width)
{
	int		i;

	i = 0;
	if (ft_strchr(flags, '-') && width > 1)
	{
		ft_putchar_fd(c, 1);
		while (width > ++i)
			ft_putchar_fd(' ', 1);
	}
	else if (width > 1)
	{

		while (width > i++ + 1)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
	else if (width <= 1)
		i = ft_putchar_fd(c, 1);
	return (i);
}

int	ft_argument(char sym, va_list ap, t_lis *list)
{
	if (sym == 'd' || sym == 'i')
		return (ft_printf_i(va_arg(ap, int), list));
	else if (sym == 's')
		return (ft_printf_s(va_arg(ap, char *), list));
	else if (sym == 'u')
		return (ft_printf_u(va_arg(ap, unsigned int), list));
	else if (sym == '%')
		return (ft_putchar_fd('%', 1));
	else if (sym == 'x' || sym == 'X')
		return (ft_printf_x(va_arg(ap, unsigned int), sym, list));
	else if (sym == 'p')
		return (ft_printf_p(va_arg(ap, unsigned long int), list));
	else if (sym == 'c')
		return (ft_printf_c(va_arg(ap, int), list->flags, list->width));
	return (0);
}

int	ft_discharge(int nbr)
{
	int		count;

	count = 0;
	while (nbr)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}
	
char	*ft_check_flags(const char *str)
{
	char	*flags;
	char	*set;
	int		i;

	set = "-0# +";
	flags = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!flags)
		return (0);
	i = -1;
	while (*str)
	{
		if (!ft_strchr(set, *str))
		{
			flags[++i] = '\0';
			return (flags);
		}
		//if (ft_strchr(flags, *str))
		//{
		//	free(flags);
		//	return (0);
		//}
		flags[++i] = *str;
		str++;
	}
	free(flags);
	return (0);
}

t_lis	*ft_list(const char *str)
{
	t_lis	*list;

	list = (t_lis *)malloc(sizeof(t_lis));
	if (!list)
		return (0);
	list->flags = ft_check_flags(str);
	list->width = ft_atoi(str + ft_strlen(list->flags));
	list->precision = 0;
	list->pwidth = 0;
	if (*(str + ft_strlen(list->flags) + ft_discharge(list->width)) == '.')
	{
		list->precision = 1;
		list->pwidth = ft_atoi(str + ft_strlen(list->flags) + ft_discharge(list->width) + 1);
	}
	return (list);
}

void	ft_dellist(t_lis *list)
{
	free(list->flags);
	list->flags = NULL;
	free(list);
	list = NULL;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_lis	*list;
	int		i;
	int		count;

	i = -1;
	count = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		else
		{
			list = ft_list(&format[++i]);
			i += ft_discharge(list->width) + ft_strlen(list->flags)
				+ list->precision + ft_discharge(list->pwidth);
			if (format[i] == '0')
				i++;
			count += ft_argument(format[i], ap, list);
			ft_dellist(list);
		}				
	}
	va_end(ap);
	return (count);
}
