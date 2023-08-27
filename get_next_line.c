/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:21:39 by telufulu          #+#    #+#             */
/*   Updated: 2023/08/27 19:08:51 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*res;
	char		*aux;

	res = 0;
	while (!strchr(aux, '\n'))
	{
		aux = res;
		res = ft_strjoin(res, buffer);
		if (!res)
			return (NULL);
		if (aux)
			free(aux);
		read(fd, buffer, BUFFER_SIZE);
	}
	write(1, res, strlen(res));
	return (res);
}
