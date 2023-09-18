/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:15:11 by telufulu          #+#    #+#             */
/*   Updated: 2023/09/18 00:48:27 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../../get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define NB_OF_TEST 8

typedef struct	s_store
{
	char	*path;
	char	*expected;
}				t_store;

char	*strjoin(char const *s1, char const *s2);
void	init_store(t_store *store);
#endif
