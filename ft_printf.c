/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:12:30 by daykim            #+#    #+#             */
/*   Updated: 2022/04/21 17:12:30 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	index;
	int		cnt;

	cnt = 0;
	index = 0;
	va_start(ap, format);
	while (format[index])
	{
		if (format[index] != '%')
		{
			index++;
			cnt += ft_putchar_cnt(format[index]);
		}
		else
		{
			index++;
			cnt += check_type((char)format[index], &ap);
		}
	}
	va_end(ap);
	return (cnt);
}

int	check_type(char conv, va_list *ap)
{
	if (conv == '%')
		return (ft_putchar_cnt('%'));
	if (conv == 'c')
		return (ft_putchar_cnt(va_arg(*ap, int)));
	else if (conv == 's')
		return (ft_putstr_cnt(va_arg(*ap, char *)));
	// else if (conv == 'p')

	else if (conv == 'd' || conv == 'i')
		return (ft_putnbr_cnt(va_arg(*ap, int)));
	// else if (conv == 'u')
	
	else if (conv == 'x')
		return (ft_puthex_cnt(va_arg(*ap, unsigned int), 'x'));
	else if (conv == 'X')
		return (ft_puthex_cnt(va_arg(*ap, unsigned int), 'X'));	
	else
		return (0);
}
