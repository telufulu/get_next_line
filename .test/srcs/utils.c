/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:33:53 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/18 00:59:36 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	res = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[x])
		res[i++] = s2[x++];
	return (res);
}

void	init_store(t_store *store)
{
	store[0] = (t_store){"files/41_no_nl", "01234567890123456789012345678901234567890"};
	store[1] = (t_store){"files/42_no_nl", "012345678901234567890123456789012345678901"};
	store[2] = (t_store){"files/41", "01234567890123456789012345678901234567890\n"};
	store[3] = (t_store){"files/42", "012345678901234567890123456789012345678901\n"};
	store[4] = (t_store){"files/hola", "Hola\nEsto es una prueba\nEsta es la segunda línea\n\nY esta la quinta\n"};
	store[5] = (t_store){"files/lorem", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n\nSed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?\n"};
	store[6] = (t_store){"files/one_char", "X\n"};
	store[7] = (t_store){"files/empty", NULL};
}
