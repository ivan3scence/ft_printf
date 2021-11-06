/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:37:50 by sdonny            #+#    #+#             */
/*   Updated: 2021/10/11 15:18:46 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	k;
	int	reverse[12];

	k = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		k = -1;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		reverse[i++] = (n % 10) * k + 48;
		n = n / 10;
	}
	n = i + (1 - k) / 2;
	while (i-- > 0)
		ft_putchar_fd(reverse[i], fd);
	return (n);
}
