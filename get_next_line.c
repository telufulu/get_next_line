/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:21:39 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/18 12:51:31 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_buffer(int fd, char **store)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	size_t	rd;

	rd = 0;
	while (rd <= BUFFER_SIZE)
		buffer[rd++] = '\0';
	rd = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
			return (-1);
		buffer[rd] = '\0';
		aux = (*store);
		(*store) = ft_strjoin((*store), buffer);
		free(aux);
	}
	return (rd);
}

static size_t	get_line(char *store, char **res)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (store[len] != '\0' && store[len] != '\n')
		len++;
	if (store[len] == '\n')
		len++;
	(*res) = (char *)ft_calloc(sizeof(char), len + 1);
	if (!(*res))
		return (0);
	while (i < len)
		(*res)[i++] = *store++;
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*res;
	char		*aux;
	size_t		len;

	if (fd < 0 || fd > MAX_FD || read(fd, 0, 0) < 0)
		return (free(store), NULL);
	if (!store)
		store = ft_calloc(1, 1);
	if (!store)
		return (NULL);
	if (get_buffer(fd, &store) < 0)
		return (free(store), NULL);
	len = get_line(store, &res);
	if (!len)
		return (free(store), free(res), NULL);
	aux = store;
	store = ft_strdup(store + len);
	free(aux);
	if (!store)
		return (NULL);
	return (res);
}
