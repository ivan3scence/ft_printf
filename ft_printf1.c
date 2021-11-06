/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:37:50 by sdonny            #+#    #+#             */
/*   Updated: 2021/10/31 15:18:46 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunbr_fd(unsigned int n, int fd)
{
	char	*reverse;
	int		i;
	int		count;

	if (fd == -1)
		return (0);
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (!n)
		return (1);
	i = 0;
	reverse = (char *)malloc(sizeof(char) * 11);
	if (!reverse)
		return (0);
	while (n != 0)
	{
		reverse[i++] = (n % 10) + 48;
		n = n / 10;
	}
	count = i;
	while (i-- > 0)
		write(1, &reverse[i], 1);
	free(reverse);
	return (count);
}

static int	ft_puthex(unsigned long int nbr, char sym, int i)
{
	char	*hex;
	char	*base;

	if (nbr == 0)
		write(1, "0", 1);
	if (nbr == 0)
		return (1);
	hex = (char *)malloc(sizeof(char) * 20);
	if (!hex)
		return (0);
	base = "0123456789abcdef";
	if (sym == 'X')
		base = "0123456789ABCDEF";
	while (nbr)
	{
		hex[++i] = base[nbr % 16];
		nbr = nbr / 16;
	}
	hex[++i] = '\0';
	nbr = i;
	while (--i >= 0)
		ft_putchar_fd(hex[i], 1);
	free(hex);
	return (nbr);
}

static int	ft_print_arg(char sym, va_list ap)
{
	if (sym == 'd' || sym == 'i')
		return (ft_putnbr_fd((int)va_arg(ap, int), 1));
	else if (sym == 'c')
		return (ft_putchar_fd((char)va_arg(ap, int), 1));
	else if (sym == 's')
		return (ft_putstr_fd((char *)va_arg(ap, void *), 1));
	else if (sym == 'u')
		return (ft_putunbr_fd(va_arg(ap, unsigned int), 1));
	else if (sym == '%')
		return (ft_putchar_fd('%', 1));
	else if (sym == 'x' || sym == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), sym, -1));
	else if (sym == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (2 + ft_puthex(va_arg(ap, unsigned long int), 'x', -1));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ii;
	int		count;

	if (!format)
		return (-1);
	i = -1;
	ii = 0;
	count = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
			count += ft_print_arg(format[++i], ap);
		else
		{
			ii++;
			write(1, &format[i], 1);
		}
	}
	va_end(ap);
	return (count + ii);
}
