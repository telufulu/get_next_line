/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:20:05 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/11 13:37:20 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
//#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*res;
	size_t	i;
	size_t	lines;

	i = 0;
	lines = 2;
	fd = open(".test/hola.txt", O_RDONLY);
	//fd = 0;
	while (i < lines)
	{
		res = get_next_line(fd);
		printf("%s", res);
		free(res);
		i++;
	}
	return (0);
}
