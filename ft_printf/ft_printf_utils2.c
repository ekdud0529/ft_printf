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

int	ft_puthex_cnt(unsigned int num, char x)
{
	char	*hex;
	char	changed[11];
	int		index;
	int		cnt;

	if (x == 'X')
		hex = "0123456789ABCDEF";
	else if (x == 'x')
		hex = "0123456789abcdef";
	index = 0;
	if (num == 0)
		changed[index++] = '0';
	while (num)
	{
		changed[index] = hex[num % 16];
		num /= 16;
		index++;
	}
	cnt = 0;
	while (--index >= 0)
	{
		cnt += ft_putchar_cnt(changed[index]);
	}
	return (cnt);
}

int	ft_unsigned_cnt(unsigned int num)
{
	int		cnt;
	int		index;
	char	changed[11];

	cnt = 0;
	index = 0;
	if (num == 0)
		changed[index++] = 0;
	while (num)
	{
		changed[index] = num % 10;
		num /= 10;
		index++;
	}
	while (--index >= 0)
	{
		ft_putchar_cnt(changed[index] + '0');
		cnt++;
	}
	return (cnt);
}

int	ft_putp_cnt(unsigned long addr)
{
	int		cnt;
	int		index;
	char	changed[20];
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "0x", 2);
	if (!addr)
	{
		write(1, "0", 1);
		return (3);
	}
	cnt = 0;
	index = 0;
	while (addr)
	{
		changed[index++] = hex[addr % 16];
		addr /= 16;
	}
	while (--index >= 0)
	{
		ft_putchar_cnt(changed[index]);
		cnt++;
	}
	return (cnt + 2);
}
