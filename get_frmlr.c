/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frmlr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 15:32:29 by jburet            #+#    #+#             */
/*   Updated: 2014/02/12 14:22:00 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			nb_comment(char **entry)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (entry[i])
	{
		if (entry[i][0] && entry[i][1])
		{
			if (entry[i][0] == '#' && entry[i][1] != '#')
				nb++;
		}
		i++;
	}
	return (nb);
}

void		get_special_line(char **entry, t_frmlr *fml, int num)
{
	char	**line;

	if (entry[num + 1])
		line = ft_strsplit(entry[num + 1], ' ');
	else
		return ;
	if (ft_strncmp(entry[num], "##start", 7) == 0)
	{
		fml->in.name = ft_strdup(line[0]);
		fml->in.crd.x = ft_atoi(line[1]);
		fml->in.crd.y = ft_atoi(line[2]);
	}
	if (ft_strncmp(entry[num], "##end", 5) == 0)
	{
		fml->out.name = ft_strdup(line[0]);
		fml->out.crd.x = ft_atoi(line[1]);
		fml->out.crd.y = ft_atoi(line[2]);
		fml->out.full = 0;
	}
	free(line);
}

void		get_a_room(char *line, t_frmlr *fml)
{
	int		i;
	char	**t;

	i = 0;
	t = ft_strsplit(line, ' ');
	while (fml->salles[i] != NULL)
		i++;
	fml->salles[i] = (t_salle *)ft_memalloc(sizeof(t_salle));
	fml->salles[i]->name = ft_strdup(t[0]);
	fml->salles[i]->crd.x = ft_atoi(t[1]);
	fml->salles[i]->crd.y = ft_atoi(t[2]);
	fml->salles[i]->tub = (t_salle **)ft_memalloc(sizeof(t_salle **));
	if (ft_strcmp(fml->salles[i]->name, fml->in.name) == 0)
		fml->salles[i]->full = fml->nb_frms;
	else
		fml->salles[i]->full = 0;
	free(t);
}

int		get_a_tube(char *line, t_frmlr *fml)
{
	int		i;
	char	**t;

	i = 0;
	t = ft_strsplit(line, '-');
	while (fml->tubes[i] != NULL)
		i++;
	fml->tubes[i] = (t_tube *)ft_memalloc(sizeof(t_tube));
	fml->tubes[i]->start = ft_strdup(t[0]);
	if (!t[1])
	{
		fml->tubes[i]->end = NULL;
		return (0);
	}
	fml->tubes[i]->end = ft_strdup(t[1]);
	free(t);
	return (1);
}

void		get_a_comment(char *line, t_frmlr *fml)
{
	int		i;

	i = 0;
	while (fml->comment[i] != NULL)
		i++;
	fml->comment[i] = ft_strdup(line);
}
