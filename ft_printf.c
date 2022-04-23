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
	int		cnt;

	cnt = 0;
	va_start(ap, format);
	while(format[cnt])
	{
		if (format[cnt] != '%')
		{
			cnt++;
			// 출력
			cnt++;
		}
		else
		{
			cnt += check_type((char)format[cnt]);
		}
	}
	va_end(ap);
	return (cnt);
}

int	check_type(char	conv)
{
	if(conv == 'c' || conv == '%')
	{
		
	}
	else if(conv == 's')
	{

	}
	else if(conv == 'p')
	{

	}
	else if(conv == 'd' || conv == 'i')
	{

	}
	else if(conv == 'i')
	{

	}
	else if(conv == 'u')
	{

	}
	else if(conv == 'x')
	{

	}
	else if(conv == 'X')
	{

	}
	else
		return (0);
}