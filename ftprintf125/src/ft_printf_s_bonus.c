/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:25:20 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/08 19:25:21 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	while ((!list->precision && str[j])
		|| (list->precision && list->pwidth > j && str[j]))
		write(1, &str[j++], 1);
	if (ft_strchr(list->flags, '-') && list->width > i + j)
		i += ft_printchrit(' ', list->width - i - j);
	return (i + j);
}
