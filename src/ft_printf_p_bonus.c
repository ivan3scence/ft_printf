/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:25:26 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/08 19:25:28 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_p(unsigned long int nbr, t_lis *list)
{
	int		i;
	char	*str;
	char	*n;

	n = ft_hex(nbr, 'x', -1);
	str = ft_strjoin("0x", n);
	free(n);
	i = 0;
	if (!ft_strchr(list->flags, '-') && !ft_strchr(list->flags, '0'))
		i += ft_printchrit(' ', list->width - ft_strlen(str));
	i += ft_putstr_fd(str, 1);
	if (ft_strchr(list->flags, '-'))
		i += ft_printchrit(' ', list->width - i);
	free(str);
	return (i);
}
