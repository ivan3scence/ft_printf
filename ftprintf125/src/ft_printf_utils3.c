/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:26:00 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/08 19:26:02 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_digits(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(long int n)
{
	char		*str;
	long int	i;

	i = n;
	n = ft_digits(n);
	str = (char *) malloc(sizeof(char) * (n + 2));
	if (!str)
		return (0);
	if (i < 0)
	{
		str[0] = '-';
		n++;
		i = -i;
	}
	str[n] = '\0';
	if (i == 0)
		str[0] = '0';
	if (i == 0)
		str[1] = '\0';
	while (i)
	{
		str[--n] = i % 10 + '0';
		i = i / 10;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	long long int	n;
	long long int	k;
	int				i;

	k = 1;
	n = 0;
	i = 0;
	while ((str[i]) && (((str[i] > 8) && (str[i] < 14)) || (str[i] == 32)))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i++] == 45)
			k = k * (-1);
	}
	while (str[i] && !(str[i] < 48 || str[i] > 57))
	{
		n = n * 10 + str[i++] - 48;
		if (n < 0)
		{
			if (k > 0)
				return (-1);
			return (0);
		}
	}
	return (n * k);
}
