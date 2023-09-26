/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:56:55 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/26 17:25:31 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*aux;
	size_t	len;

	len = count * size;
	aux = malloc(len);
	if (!aux)
		return (0);
	while (len--)
		aux[len] = 0;
	return (aux);
}

/*size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while (dstsize > 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}*/

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_calloc(sizeof(char), (ft_strlen(s1) + 1));
	if (!res)
		return (0);
	while (*s1 != '\0')
		res[i++] = (char)*s1++;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux != '\0')
	{
		if (*aux == (char)c)
			return (aux);
		aux++;
	}
	if (*aux == (char)c)
		return (aux);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	res = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[x])
		res[i++] = s2[x++];
	return (res);
}
