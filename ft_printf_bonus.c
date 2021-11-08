/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:25:30 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/08 18:40:31 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_putxstr_fd(char *s, int fd)
// {
// 	int	len;

// 	if (!s)
// 	{
// 		write(fd, "0", 1);
// 		return (1);
// 	}
// 	len = ft_strlen(s);
// 	if (fd != -1)
// 		write(fd, s, len);
// 	return (len);
// }

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
		flags[++i] = *str;
		str++;
	}
	free(flags);
	return (0);
}

int	ft_print(const char *format, int i, int count, va_list ap)
{
	t_lis	*list;

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
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = -1;
	count = 0;
	va_start(ap, format);
	count = ft_print(format, i, count, ap);
	va_end(ap);
	return (count);
}
