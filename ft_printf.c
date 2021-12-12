/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:45:35 by tyuuki            #+#    #+#             */
/*   Updated: 2021/12/12 13:11:25 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_symb(char symb)
{
	write(1, &symb, 1);
	return (1);
}

int	pointer_adress(unsigned long n)
{
	char	*arr;
	int		i;

	i = 1;
	arr = "0123456789abcdef0123456789ABCDEF";
	if (n < 16)
		write(1, &arr[n], 1);
	else
	{
		i += pointer_adress(n / 16);
		pointer_adress(n % 16);
	}
	return (i);
}

int	pars_data(va_list ap, const char *format, int i)
{
	int	len;

	len = 0;
	if (format[i] == 'd' || format[i] == 'i')
		len += ft_decimal(ap);
	if (format[i] == 'c')
		len += ft_char(ap);
	if (format[i] == 's')
		len += ft_string(ap);
	if (format[i] == 'x')
		len += convert_hex(va_arg(ap, int), 0);
	if (format[i] == 'X')
		len += convert_hex(va_arg(ap, int), 1);
	if (format[i] == '%')
		len += ft_putchar('%') + 1;
	if (format[i] == 'p')
	{
		ft_putstr("0x");
		len += pointer_adress(va_arg(ap, unsigned long int)) + 2;
	}
	if (format[i] == 'u')
		len += unsigned_decimal(ap);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += pars_data(ap, format, i + 1);
			i++;
		}
		else
			len += write_symb(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
