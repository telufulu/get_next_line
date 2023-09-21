/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:20:05 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/21 18:20:12 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	int		fd;
	int		x;
	t_store	test[NB_OF_TEST];
	char	*res;
	char	*aux;
	char	*aux2;

	x = 0;
	res = 0;
	aux = 0;
	init_store(test);
	while (x < NB_OF_TEST)
	{
		printf("Sale\n");
		aux2 = "";
		fd = open(test[x].path, O_RDONLY);
		res = get_next_line(fd);
		while (aux2)
		{
			aux = res;
			aux2 = get_next_line(fd);
			res = strjoin(res, aux2);
			//free(aux);
			//free(aux2);
		}
		if ((res && !strcmp(res, test[x].expected)) || (!test[x].expected && !res))
			printf("test %i: \x1b[32mOK\x1b[0m\n", x);
		else
			printf("%stest %i: \x1b[31mKO\x1b[0m\n", res, x);
		close(fd);
		if (res)
			free(res);
		x++;
	}
	return (0);
}
