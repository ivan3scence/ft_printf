/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:26:00 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/08 19:26:02 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_precision(char *n, int width)
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

int	ft_printchrit(char c, int t)
{
	int		i;

	i = 0;
	while (t-- > 0)
		i += ft_putchar_fd(c, 1);
	return (i);
}
