/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:26:00 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/08 19:26:02 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	if (fd != -1)
		write(fd, s, len);
	return (len);
}

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

int	ft_putchar_fd(char c, int fd)
{
	if (fd != -1)
		write(fd, &c, 1);
	return (1);
}

int	ft_strchr(const char *s, int c)
{
	c = c % 128;
	if (c == '\0')
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const	*s2)
{
	char	*joined;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = -1;
	joined = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (0);
	while (*s1)
		joined[++i] = *s1++;
	while (*s2)
		joined[++i] = *s2++;
	joined[++i] = '\0';
	return (joined);
}
