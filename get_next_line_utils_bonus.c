/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:23:16 by igenial           #+#    #+#             */
/*   Updated: 2023/06/21 22:26:16 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = (ft_strlen(dst));
	src_len = (ft_strlen(src));
	i = 0;
	if (dst_len >= size)
		return (size + src_len);
	while ((dst_len + i) < (size - 1) && src[i])
	{
		dst[dst_len + i] = ((char *)src)[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*strmalloc;
	size_t	i;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
	{
		start = slen;
		len = 0;
	}
	if (start + len > slen)
		len = slen - start;
	strmalloc = ft_calloc(len + 1, sizeof(char));
	if (!strmalloc)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		strmalloc[i] = s[start];
		i++;
		start++;
	}
	return (strmalloc);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	int		result;

	pointer = NULL;
	result = nmemb * size;
	if (!nmemb || !size || nmemb == result / size)
		pointer = malloc(result);
	if (pointer)
		while (result--)
			*(unsigned char *)(pointer + result) = 0;
	return (pointer);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && *s)
	{
		s++;
		i++;
	}
	return (i);
}
