/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:56:55 by telufulu          #+#    #+#             */
/*   Updated: 2023/08/27 19:10:11 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	res_len;

	if (s1)
		res_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	else
		res_len = ft_strlen(s2);
	write(1, "Entra\n", 6);
	res = calloc(sizeof(char), res_len);
	if (!res)
		return (NULL);
	strlcpy(res, s1, ft_strlen(s1) + 1);
	strlcat(res, s2, res_len);
	return (res);
}
