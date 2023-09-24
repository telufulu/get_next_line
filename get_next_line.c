/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:45:23 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/25 01:11:00 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buffer(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*res;
	char	*aux;
	int		rd;

	res = 0;
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = 0;
		if (rd < 0)
			return (free(res), NULL);
		if (!rd)
			return (res);
		aux = res;
		res = ft_strjoin(res, buffer);
		free(aux);
		if (!res)
			return (res);
	}
	return (res);
}

static char	*get_line(char **store)
{
	size_t	len;
	size_t	i;
	char	*res;
	char	*aux;

	len = 0;
	i = 0;
	aux = 0;
	while ((*store)[len] && (*store)[len] != '\n')
		len++;
	if ((*store)[len] == '\n')
		len++;
	res = ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	while ((*store)[i] && i < len)
	{
		res[i] = (*store)[i];
		i++;
	}
	aux = (*store);
	(*store) = ft_strdup((*store) + len);
	if (!(*store))
		return (free(aux), free(res), NULL);
	return (free(aux), res);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*res;
	char		*aux;

	aux = 0;
	res = 0;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(store), NULL);
	if (!store || !ft_strchr(store, '\n'))
	{
		aux = store;
		store = get_buffer(fd);
		free(aux);
	}
	if (!store)
		return (NULL);
	res = get_line(&store);
	if (!res)
		return (free(store), NULL);
	return (res);
}
