/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 19:43:13 by jburet            #+#    #+#             */
/*   Updated: 2014/01/18 16:33:13 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		in_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == '\n')
			return (0);
	}
	return (1);
}

char	*get_fd(const int fd, int *i)
{
	char	*dst;
	char	*tmp;
	int		j;

	j = 1;
	*i = 1;
	dst = ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	tmp = ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	while (j == 1 && *i > 0)
	{
		*i = read(fd, tmp, BUFF_SIZE);
		if (*i >= 0)
		{
			tmp[*i] = '\0';
			dst = ft_strjoin(dst, tmp);
		}
		j = in_line(dst);
	}
	free(tmp);
	return (dst);
}

char	*rest_in_get(char *get)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	while (get[i] != '\n' && get[i] != '\0')
		i++;
	dst = ft_memalloc(sizeof(char) * (ft_strlen(get) - i) + 1);
	i++;
	while (get[i] != '\0')
		dst[j++] = get[i++];
	dst[j] = '\0';
	return (dst);
}

char	*frist_line(char *str, int *j)
{
	char	*dst;
	int		i;

	i = 0;
	*j = 1;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		*j = 0;
	dst = ft_memalloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		dst[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
		*j = 0;
	dst[i] = '\0';
	return (dst);
}

int		get_next_line(const int fd, char **line)
{
	char			*get;
	static char		*stay;
	static int		k = 0;
	int				i;

	if (k == 0)
	{
		stay = ft_memalloc(0);
		get = get_fd(fd, &i);
		if (i == -1)
			return (-1);
		k++;
	}
	else
	{
		get = ft_strjoin(stay, get_fd(fd, &i));
		if (i == -1)
			return (-1);
	}
	stay = rest_in_get(get);
	*line = frist_line(get, &i);
	free(get);
	if (i == 0)
		return (0);
	return (1);
}

