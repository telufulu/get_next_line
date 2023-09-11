/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:21:39 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/10 20:12:35 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	len_line(char *res)
{
	size_t	i;

	i = 0;
	while (res && res[i] != '\n' && res[i] != '\0')
		i++;
	if (res[i] == '\n')
		i++;
	return (i);
}

static char	*add_buffer(char *store, char *buffer)
{
	char		*aux;

	aux = ft_strjoin(store, buffer);
	if (!aux)
		return (NULL);
	free(store);
	return (aux);
}

static char	*next_line(char **store)
{
	char	*res;
	size_t		len;
	char	*aux;
	size_t	i;

	len = len_line((*store));
	res = ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	i = 0;
	aux = (*store);
	while (i <= len)
		res[i++] = *(*store)++;
	free(aux);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*res;
	char		buffer[BUFFER_SIZE + 1];
	int			flag;

	res = NULL;
	buffer[BUFFER_SIZE] = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!store || !ft_strchr(store, '\0') || !ft_strchr(store, '\n'))
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag <= 0)
		{
			if (store)
				free(store);
			return (NULL);
		}
		store = add_buffer(store, buffer);
		if (!store)
			return (NULL);
	}
	if (store && (ft_strchr(store, '\n') || ft_strchr(store, '\0')))
		res = next_line(&store);
	return (res);
}
