/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:20:05 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/24 21:13:06 by telufulu         ###   ########.fr       */
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
	aux2 = 0;
	init_store(test);
	while (x < NB_OF_TEST)
	{
		fd = open(test[x].path, O_RDONLY);
		res = get_next_line(fd);
		while (res)
		{
			aux = get_next_line(fd);
			if (!aux)
				break;
			aux2 = res;
			res = strjoin(res, aux);
			free(aux);
			aux = 0;
			free(aux2);
			aux2 = 0;
		}
		if ((test[x].expected == res) || (res && *res && !strcmp(res, test[x].expected)))
			printf("test %i: \x1b[32mOK\x1b[0m\n", x);
		else
			printf("%stest %i: \x1b[31mKO\x1b[0m\n", res, x);
		close(fd);
		free(res);
		x++;
	}
	return (0);
}
