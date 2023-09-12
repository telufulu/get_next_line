/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:33:53 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/13 00:14:05 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

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
}
