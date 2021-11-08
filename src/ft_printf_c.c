/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:25:03 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/08 19:25:06 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
