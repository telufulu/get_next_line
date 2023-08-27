/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:20:18 by telufulu          #+#    #+#             */
/*   Updated: 2023/08/27 18:58:33 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10

# include <unistd.h>
# include <stdlib.h>

// borrar
# include <string.h>

// get_next_line
char	*get_next_line(int fd);

// utils
char	*ft_strjoin(char const *s1, char const *s2);
#endif
