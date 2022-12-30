/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:36:38 by htalhaou          #+#    #+#             */
/*   Updated: 2022/10/22 23:49:57 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbru(unsigned int nb, int *count)

{
	if (nb > 9)
	{
		ft_putnbru(nb / 10, count);
		ft_putnbru(nb % 10, count);
	}
	else
	{
		ft_putchar(nb + '0', count);
	}
}
