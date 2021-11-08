/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:26:16 by sdonny            #+#    #+#             */
/*   Updated: 2021/11/08 19:26:18 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_lis	*ft_list(const char *str)
{
	t_lis	*list;

	list = (t_lis *)malloc(sizeof(t_lis));
	if (!list)
		return (0);
	list->flags = ft_check_flags(str);
	list->width = ft_atoi(str + ft_strlen(list->flags));
	list->precision = 0;
	list->pwidth = 0;
	if (*(str + ft_strlen(list->flags) + ft_discharge(list->width)) == '.')
	{
		list->precision = 1;
		list->pwidth = ft_atoi(str + ft_strlen(list->flags)
				+ ft_discharge(list->width) + 1);
	}
	return (list);
}

void	ft_dellist(t_lis *list)
{
	free(list->flags);
	list->flags = NULL;
	free(list);
	list = NULL;
}
