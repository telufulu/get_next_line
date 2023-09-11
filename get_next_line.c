/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:21:39 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/11 20:56:05 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_buffer(int fd, char **store)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	size_t	rd;

	buffer[BUFFER_SIZE] = '\0';
	rd = 0;
	while (!ft_strchr(buffer, '\n') || !ft_strchr(buffer, '\0'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0 || rd > MAX_FD)
			return (0);
		if (store)
			aux = (*store);
		(*store) = ft_strjoin((*store), buffer);
		if (aux)
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
	(*res) = ft_calloc(sizeof(char), len + 1);
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
	size_t		rd;

	res = NULL;
	if (fd < 0 || fd > MAX_FD)
		return (NULL);
	rd = get_buffer(fd, &store);
	if (!rd || (!rd && (!ft_strchr(store, '\n') || !ft_strchr(store, '\0'))))
		return (NULL);
	len = get_line(store, &res);
	if (!res)
		return (NULL);
	aux = store;
	store = ft_strdup(store + len);
	free(aux);
	return (res);
}
