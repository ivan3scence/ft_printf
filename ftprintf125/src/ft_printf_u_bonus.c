/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:25:11 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/08 19:25:14 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_u_to_s(unsigned int n, int i, char *reverse)
{
	char	*str;

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

char	*ft_utos(unsigned int n)
{
	char	*reverse;
	int		i;

	i = 0;
	reverse = (char *)malloc(sizeof(char) * 11);
	if (!reverse)
		return (0);
	return (ft_u_to_s(n, i, reverse));
}

int	ft_printf_u(unsigned int nbr, t_lis *list)
{
	char	*str;
	int		i;

	str = ft_utos(nbr);
	if (list->pwidth > (int)ft_strlen(str))
		str = ft_precision(str, list->pwidth);
	if (nbr == 0 && list->pwidth == 0 && list->precision == 1)
		str[0] = '\0';
	if (ft_strchr(list->flags, '0') && !list->precision)
		str = ft_precision(str, list->width);
	list->precision = 0;
	list->pwidth = 0;
	i = ft_printf_s(str, list);
	free(str);
	return (i);
}
