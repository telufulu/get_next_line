/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:51:24 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/22 16:25:29 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buffer(int fd)
{
	char	*buffer;
	ssize_t	rd;
	char	*res;
	char	*aux;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rd = read(fd, buffer, BUFFER_SIZE);
	res = ft_strjoin(res, buffer);
	while (rd && res && !ft_strchr(res, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (free(buffer), free(res), NULL);
		aux = res;
		res = ft_strjoin(res, buffer);
		free(aux);
	}
	return (free(buffer), res);
}

static char	*get_line(char **res, char *store)
{
	size_t	i;

	i = 0;
	while (store[i] != '\n' && store[i])
		i++;
	if (store[i] == '\n')
		i++;
	(*res) = ft_calloc(sizeof(char), i);
	if (!(*res))
		return (NULL);
	i = 0;
	while (*store != '\n' && *store)
		(*res)[i++] = *store++;
	if ((*res)[i] == '\n')
		(*res)[i] = *store++;
	return (ft_strdup(store));
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*res;
	char		*aux;

	res = 0;
	
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > MAX_FD || read(fd, 0, 0) < 0)
		return (free(store), NULL);
	if (!ft_strchr(store, '\n'))
	{
		printf("Sale\n");
		aux = get_buffer(fd);
		store = ft_strjoin(store, aux);
		free(aux);
	}
	if (!store)
		return (NULL);
	aux = store;
	store = get_line(&res, store);
	free(aux);
	if (res)
		return (res);
	return (free(store), NULL);
}
