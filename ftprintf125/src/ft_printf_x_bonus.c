/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:25:32 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/08 19:25:33 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_base(char sym)
{
	char	*base;

	base = "0123456789abcdef";
	if (sym == 'X')
		base = "0123456789ABCDEF";
	return (base);
}

char	*ft_reverse(char *hex, int i)
{
	char	*str;
	int		nbr;

	nbr = 0;
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

char	*ft_hex(unsigned long int nbr, char sym, int i)
{
	char	*hex;
	char	*base;

	hex = (char *)malloc(sizeof(char) * 20);
	if (!hex)
		return (0);
	if (!nbr)
	{
		hex[0] = '0';
		hex[1] = '\0';
		return (hex);
	}
	base = ft_base(sym);
	while (nbr)
	{
		hex[++i] = base[nbr % 16];
		nbr = nbr / 16;
	}
	return (ft_reverse(hex, i));
}

int	ft_ox(int nbr, char sym, t_lis *list)
{
	int		i;

	i = 0;
	if (ft_strchr(list->flags, '#') && nbr)
	{
		if (sym == 'x')
			i += ft_putstr_fd("0x", 1);
		else
			i += ft_putstr_fd("0X", 1);
	}
	return (i);
}

int	ft_printf_x(unsigned long int nbr, char sym, t_lis *list)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_hex(nbr, sym, -1);
	if ((int)ft_strlen(str) < list->pwidth)
		str = ft_precision(str, list->pwidth);
	if (nbr == 0 && list->pwidth == 0 && list->precision == 1)
		str[0] = '\0';
	if ((!ft_strchr(list->flags, '-') && !ft_strchr(list->flags, '0'))
		|| ((list->precision || !ft_strlen(str))
			&& ft_strchr(list->flags, '0')))
		i += ft_printchrit(' ', list->width - ft_strlen(str)
				- 2 * (ft_strchr(list->flags, '#')));
	i += ft_ox(nbr, sym, list);
	if (ft_strchr(list->flags, '0') && ft_strlen(str) && !list->precision)
		i += ft_printchrit('0', list->width - ft_strlen(str) - i);
	i += ft_putstr_fd(str, 1);
	if (ft_strchr(list->flags, '-'))
		i += ft_printchrit(' ', list->width - i);
	free(str);
	return (i);
}
