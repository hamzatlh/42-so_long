/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:13:32 by htalhaou          #+#    #+#             */
/*   Updated: 2022/10/24 14:41:00 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(va_list ap, const char *str, int *count)

{
	if (*str == '%')
		ft_putchar(*str, count);
	else if (*str == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (*str == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(ap, int), count);
	else if (*str == 'u')
		ft_putnbru(va_arg(ap, unsigned int), count);
	else if (*str == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), 0, count);
	else if (*str == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), 1, count);
	else if (*str == 'p')
		ft_p(va_arg(ap, unsigned long *), count);
}

int	ft_printf(const char *str, ...)

{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_check (ap, &str[i], &count);
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	return (count);
	va_end(ap);
}
