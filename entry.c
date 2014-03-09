/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 14:41:14 by jburet            #+#    #+#             */
/*   Updated: 2014/02/05 16:46:20 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

char		**parse_stdin(void)
{
	char	**entry;
	int		i;
	int		j;
	int		stop;

	entry = (char **)ft_memalloc(sizeof(char **));
	i = 0;
	stop = 1;
	while (get_next_line(0, &entry[i]) == 1 && stop == 1)
	{
		j = 0;
		while(entry[i][j])
		{
			if (entry[i][j] == '\n' || entry[i][j] == '\r')
				entry[i][j] = '\0';
			j++;
		}
		if (entry[i][0] == '\0')
			stop = 0;
		else
			i++;
	}
	entry[i] = NULL;
	return (entry);
}
