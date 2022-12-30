/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:13:56 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/03 17:18:06 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup_gnl( char *s1);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strdup_gnl(char *s1);
#endif