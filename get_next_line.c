/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:45:23 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/25 10:29:06 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_buffer(int fd, char **store)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	int		rd;

	rd = 0;
	while (rd < BUFFER_SIZE)
		buffer[rd++] = 0;
	rd = 1;
	while (rd > 0 && !ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (-1);
		if (!rd)
			return (0);
		buffer[rd] = 0;
		aux = (*store);
		(*store) = ft_strjoin((*store), buffer);
		free(aux);
		if (!(*store))
			return (-1);
	}
	return (0);
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
	int			aux;

	res = 0;
	aux = 0;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(store), NULL);
	if (!store || !ft_strchr(store, '\n'))
		aux = get_buffer(fd, &store);
	if (!store || !*store || aux < 0)
		return (free(store), NULL);
	res = get_line(&store);
	if (!res)
		return (free(store), NULL);
	return (res);
}
