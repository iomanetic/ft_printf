/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:52:56 by tyuuki            #+#    #+#             */
/*   Updated: 2021/12/12 17:31:33 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(va_list ap)
{
	char	symb;

	symb = (char) va_arg(ap, int);
	ft_putchar(symb);
	return (1);
}

int	ft_decimal(va_list ap)
{	
	char	*string;
	int		len;

	len = 0;
	string = ft_itoa(va_arg(ap, int));
	if (!string)
	{
		write(1, "(null)", 1);
		free(string);
		string = NULL;
		return (6);
	}
	len = ft_strlen(string);
	ft_putstr(string);
	free(string);
	string = NULL;
	return (len);
}

int	ft_string(va_list ap)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_putstr(va_arg(ap, char *));
	if (!str)
	{
		write(1, "(null)", 6);
		free(str);
		str = NULL;
		return (6);
	}
	len = ft_strlen(str);
	return (len);
}

int	convert_hex(unsigned int n, int type)
{
	char	*arr;
	int		i;

	i = 1;
	arr = "0123456789abcdef0123456789ABCDEF";
	if (n < 16)
		write(1, &arr[n + 16 * type], 1);
	else
	{
		i += convert_hex(n / 16, type);
		convert_hex(n % 16, type);
	}
	return (i);
}

int	unsigned_decimal(va_list ap)
{
	char	*string;
	int		len;

	len = 0;
	string = ft_utoa(va_arg(ap, unsigned int));
	if (!string)
	{
		write(1, "(null)", 1);
		free(string);
		string = NULL;
		return (6);
	}
	ft_putstr(string);
	len = ft_strlen(string);
	free(string);
	string = NULL;
	return (len);
}
