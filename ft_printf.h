/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:37:50 by sdonny            #+#    #+#             */
/*   Updated: 2021/10/31 15:18:46 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_lis
{
	char	*flags;
	int		width;
	int		precision;
	int		pwidth;
}	t_lis;
int			ft_printf(const char *format, ...);
char		*ft_precision(char *n, int width);
long int	ft_abs(int nbr);
int			ft_printchrit(char c, int t);
int			ft_printf_i_sym(int nbr, char *n, t_lis *list);
int			ft_printfi(int nbr, t_lis *list, char *n, int i);
int			ft_printf_i(int nbr, t_lis *list);
int			ft_printf_s(char *str, t_lis *list);
char		*ft_u_to_s(unsigned int n, int i, char *reverse);
char		*ft_utos(unsigned int n);
int			ft_printf_u(unsigned int nbr, t_lis *list);
char		*ft_base(char sym);
char		*ft_reverse(char *hex, int i);
char		*ft_hex(unsigned long int nbr, char sym, int i);
int			ft_ox(int nbr, char sym, t_lis *list);
int			ft_printf_x(unsigned long int nbr, char sym, t_lis *list);
int			ft_putxstr_fd(char *s, int fd);
int			ft_printf_p(unsigned long int nbr, t_lis *list);
int			ft_printf_c(char c, char *flags, int width);
int			ft_argument(char sym, va_list ap, t_lis *list);
int			ft_discharge(int nbr);
char		*ft_check_flags(const char *str);
t_lis		*ft_list(const char *str);
void		ft_dellist(t_lis *list);;
#endif
