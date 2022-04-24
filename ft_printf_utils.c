/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:59:38 by daykim            #+#    #+#             */
/*   Updated: 2022/04/22 16:59:38 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_cnt(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr_cnt(char *arg)
{
	int	cnt;
	int	index;

	cnt = 0;
	index = 0;
	if (!arg[index])
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (arg[index])
	{
		cnt += ft_putchar_cnt(arg[index]);
		index++;
	}
	return (cnt);
}

static int	ft_putnbr_cnt(int n)
{
	int			nums[10];
	long long	num;
	int			index;
	int			cnt;

	cnt = 0;
	num = n;
	if (n < 0)
	{
		cnt += ft_putchar_cnt('-');
		num *= -1;
	}
	index = 0;
	if (num == 0)
		nums[index++] = 0;
	while (num)
	{
		nums[index++] = num % 10;
		num /= 10;
	}
	while (index--)
		cnt += ft_putchar_cnt((nums[index] + '0'));
	return (cnt);
}