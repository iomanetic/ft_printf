/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:43:35 by tyuuki            #+#    #+#             */
/*   Updated: 2021/12/12 13:12:28 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_decimal(va_list ap);
char	*ft_itoa(int n);
char	*ft_putstr(char *s);
int		ft_char(va_list ap);
int		ft_putchar(char symb);
size_t	ft_strlen(char *s);
int		ft_string(va_list ap);
int		convert_hex(unsigned int n, int type);
char	*ft_utoa(unsigned int n);
int		unsigned_decimal(va_list ap);
int		pointer_adress(unsigned long n);
#endif
