/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:51:24 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/22 12:58:02 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buffer(int fd)
{
	char	*buffer;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*aux;
	char		*res;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > MAX_FD || read(fd, 0, 0))
		return(free(store), NULL);
	aux = get_buffer(fd);
	if (!aux)
		return (NULL);
	res = get_line(aux);
	if (!res)
		return(free(store), NULL);
	store = move_store(&store);
	return (res);
}
