/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:03:28 by htalhaou          #+#    #+#             */
/*   Updated: 2022/10/23 22:48:30 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nb, int upper, int *count)

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
		ft_putnbr_base(nb / 16, upper, count);
		ft_putnbr_base(nb % 16, upper, count);
	}
}
