/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 15:32:59 by jburet            #+#    #+#             */
/*   Updated: 2014/02/05 14:48:27 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "lib/libft.h"
# define BUFF_SIZE 1

int		in_line(char *str);

char	*get_fd(const int fd, int *i);

char	*rest_in_get(char *get);

char	*frist_line(char *str, int *j);

int		get_next_line(const int fd, char **line);

#endif /*GET_NEXT_LINE_C*/

