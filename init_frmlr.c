/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frmlr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 15:25:43 by jburet            #+#    #+#             */
/*   Updated: 2014/02/10 19:34:40 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			is_room(char *line)
{
	char	**t;

	t = ft_strsplit(line, ' ');
	if (t[1] && t[2] && !t[3])
	{
		free(t);
		return (1);
	}
	free(t);
	return (0);
}

int			is_tube(char *line)
{
	char	**t;

	t = ft_strsplit(line, '-');
	if (t[0] && t[1] && !t[2])
	{
		free(t);
		return (1);
	}
	free(t);
	return (0);
}

int			nb_rooms(char **entry)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (entry[i])
	{
		if (is_room(entry[i++]))
			nb++;
	}
	return (nb);
}

int			nb_tubes(char **entry)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (entry[i])
	{
		if (is_tube(entry[i++]))
			nb++;
	}
	return (nb);
}

t_frmlr		init_fml(char **entry, t_frmlr fml)
{
	fml.nb_rooms = nb_rooms(entry);
	fml.nb_tubes = nb_tubes(entry);
	fml.salles = (t_salle **)ft_memalloc(sizeof(t_salle *) * fml.nb_rooms + 1);
	fml.tubes = (t_tube **)ft_memalloc(sizeof(t_tube *) * fml.nb_tubes + 1);
	fml.nb_frms = ft_atoi(entry[0]);
	fml.in.full = fml.nb_frms;
	fml.out.full = 0;
	fml.comment = (char **)ft_memalloc(sizeof(char *) * nb_comment(entry) + 1);
	fml.count = 0;
	return (fml);
}
