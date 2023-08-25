/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:05:48 by gtroiano          #+#    #+#             */
/*   Updated: 2023/08/22 16:05:54 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	a;
	size_t	b;

	if (dest_size <= ft_strlen(dest))
		return (dest_size + ft_strlen(src));
	a = ft_strlen(dest);
	b = 0;
	while (src[b] != '\0' && a + 1 < dest_size)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[b]));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dest == NULL || src == NULL || !dest_size)
		return (src_len);
	while (*src && --dest_size)
		*dest++ = *src++;
	*dest = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		dest_size;

	dest_size = ft_strlen(s) + 1;
	dup = (char *)malloc(sizeof(char) * dest_size);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, dest_size);
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	len_total;

	if (!s1 || !s2)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_s = (char *)malloc(sizeof(char) * len_total);
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, len_total);
	ft_strlcat(new_s, s2, len_total);
	return (new_s);
}
