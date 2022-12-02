/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:17:03 by htalhaou          #+#    #+#             */
/*   Updated: 2022/10/23 22:37:18 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
		ft_putstr("(null)", count);
	else
	{
		while (str[i] && str)
		{
			ft_putchar(str[i], count);
			i++;
		}
	}
}
