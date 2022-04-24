/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:30:40 by daykim            #+#    #+#             */
/*   Updated: 2022/04/24 16:30:40 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_cnt(unsigned int num, char x)
{
	char	*hex;
	char	changed[11];
	int		index;
	int		cnt;

	if (x == 'X')
		*hex = "0123456789ABCDEF";
	else if(x == 'x')
		*hex = "0123456789abcdef";
	index = 0;
	while (num)
	{
		changed[index] = hex[num % 16];
		num /= 16;
		index++;
	}
	cnt = 0;
	while (--index)
	{
		cnt += ft_putchar_cnt(changed[index]);
	}
	return (cnt);
}

static int	ft_unsigned_cnt(unsigned int num)
{
	int		cnt;
	int		index;
	char	changed[11];

	cnt = 0;
	index = 0;
	while (num)
	{
		changed[index] = num % 10;
		num /= 10;
		index++;
	}
	while (--index)
	{
		ft_putchar_cnt(changed[index] + '0');
		cnt++;
	}
	return (cnt);
}

static int	ft_putp_cnt()
{
	
}