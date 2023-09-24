/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:08:33 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/24 22:44:36 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_buffer(int fd, char **store)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	int		rd;
	rd = 0;
	aux = 0;
	while (rd <= BUFFER_SIZE)
		buffer[rd++] = '\0';
	rd = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (1);
		if (!rd || !*buffer)
			return (0);
		buffer[rd] = '\0';
		aux = (*store);
		(*store) = ft_strjoin((*store), buffer);
		free(aux);
		if (!(*store))
			return (1);
	}
	return (0);
}

static size_t	get_line(char *store, char **res)
{
	size_t	len;
	size_t	i;
	len = 0;
	i = 0;
	if (!store)
		return (0);
	while (store && store[len] && store[len] != '\0' && store[len] != '\n')
		len++;
	if (store[len] == '\n')
		len++;
	if (!len)
		return (0);
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
	
	res = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > MAX_FD)
		return (free(store), NULL);
	if (get_buffer(fd, &store))
		return (free(store), NULL);
	len = get_line(store, &res);
	if (!len || !res)
		return (free(store), NULL);
	if (res && store)
	{
		aux = store;
		store = ft_strdup(store + len);
		free(aux);
		return (res);
	}
	return (NULL);
}
