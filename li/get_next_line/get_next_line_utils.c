/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:13:45 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/03 17:19:22 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strjoin_gnl(char *s1, char *s2)

{
	char	*str;
	size_t	size;

	if (!s1)
		s1 = ft_strdup_gnl("");
	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_memcpy_gnl(str, s1, ft_strlen_gnl(s1));
	ft_memcpy_gnl(str + ft_strlen_gnl(s1), s2, ft_strlen_gnl(s2));
	str[size] = '\0';
	free (s1);
	return (str);
}

void	*ft_memcpy_gnl(void *dst, const void *src, size_t n)

{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup_gnl(char *s1)
{
	int		i;
	char	*dst;

	dst = (char *)malloc(ft_strlen_gnl(s1) * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char )c)
		i++;
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}
