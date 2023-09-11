/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:20:05 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/11 20:55:27 by telufulu         ###   ########.fr       */
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
	lines = 40;
	fd = open("files/empty", O_RDONLY);
	//fd = open(".test/one_line.txt", O_RDONLY);
	//fd = 0;
	printf("fd: %i\n", fd);
	while (i < lines)
	{
		res = get_next_line(fd);
		printf("%s", res);
		free(res);
		i++;
	}
	return (0);
}
