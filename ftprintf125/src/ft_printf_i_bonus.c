/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:25:38 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/08 19:25:40 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long int	ft_abs(int nbr)
{
	long int	n;

	n = nbr;
	if (n < 0)
		return (n * (-1));
	return (n);
}

int	ft_printf_i_sym(int nbr, char *n, t_lis *list)
{
	int		i;

	i = 0;
	if ((!ft_strchr(list->flags, '-') && !ft_strchr(list->flags, '0'))
		|| (list->precision && ft_strchr(list->flags, '0')))
	{
		if (nbr >= 0)
			i = ft_printchrit(' ', list->width - ft_strlen(n)
					- ft_strchr(list->flags, '+')
					- ft_strchr(list->flags, ' '));
		else
			i = ft_printchrit(' ', list->width - ft_strlen(n)
					- 1 - ft_strchr(list->flags, ' '));
	}
	return (i);
}

int	ft_printfi(int nbr, t_lis *list, char *n, int i)
{
	n = ft_itoa(ft_abs(nbr));
	if (list->pwidth > (int)ft_strlen(n))
		n = ft_precision(n, list->pwidth);
	else if (nbr == 0 && list->pwidth == 0 && list->precision == 1)
		n[0] = '\0';
	i += ft_printf_i_sym(nbr, n, list);
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
}

int	ft_printf_i(int nbr, t_lis *list)
{
	char	*n;
	int		i;

	i = 0;
	n = 0;
	return (ft_printfi(nbr, list, n, i));
}
