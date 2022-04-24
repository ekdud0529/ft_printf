/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:12:43 by daykim            #+#    #+#             */
/*   Updated: 2022/04/21 17:12:43 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	check_type(char conv, va_list *ap);

int	ft_putchar_cnt(char c);
int	ft_putstr_cnt(char *arg);
int	ft_putnbr_cnt(int n);

int	ft_puthex_cnt(unsigned int num, char x);
int	ft_unsigned_cnt(unsigned int num);
int	ft_putp_cnt(unsigned long addr);

#endif