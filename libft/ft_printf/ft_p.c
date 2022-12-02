/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:04:00 by htalhaou          #+#    #+#             */
/*   Updated: 2022/10/23 22:47:15 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base_u(unsigned long int nb, int upper, int *count)

{
	char	*base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb >= 0 && nb < 16)
	{
		ft_putchar(base[nb], count);
	}
	else
	{	
		ft_putnbr_base_u(nb / 16, upper, count);
		ft_putnbr_base_u(nb % 16, upper, count);
	}
}

void	ft_p(void *p, int *count)
{
	unsigned long	ptr;

	ptr = (unsigned long )p;
	ft_putstr("0x", count);
	ft_putnbr_base_u(ptr, 0, count);
}
