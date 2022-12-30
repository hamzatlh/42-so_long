/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:11:52 by htalhaou          #+#    #+#             */
/*   Updated: 2022/10/23 21:13:24 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h> 

void	ft_putchar(char c, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr_base(unsigned int nb, int upper, int *count);
void	ft_putnbru(unsigned int nb, int *count);
int		ft_printf(const char *str, ...);
void	ft_p(void *nb, int *count);
#endif
