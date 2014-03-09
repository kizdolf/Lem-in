/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:12:34 by jburet            #+#    #+#             */
/*   Updated: 2014/02/12 20:59:34 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_salle		*get_salle_from_tube(t_tube *tube, t_frmlr *fml, int choice)
{
	int		i;

	i = 0;
	while (fml->salles[i])
	{
		if (choice == 1)
		{
			if (ft_strcmp(fml->salles[i]->name, tube->start) == 0)
				return (fml->salles[i]);
		}
		else
		{
			if (ft_strcmp(fml->salles[i]->name, tube->end) == 0)
				return (fml->salles[i]);
		}
		i++;
	}
	return (NULL);
}

int		move_one_frm(t_salle *less, t_salle *more, t_frmlr *fml, int frm, t_mlx ml)
{
	if (more->full == 0 || ft_strcmp(more->name, fml->out.name) == 0)
	{
		if (ft_strcmp(more->name, less->name) != 0)
		{
			if (ft_strcmp(more->name, fml->out.name) == 0)
				fml->out.full++;
			more->full++;
			if (ft_strcmp(less->name, fml->in.name) == 0)
				fml->in.full--;
			less->full--;
			ft_putchar('L');
			ft_putnbr(frm);
			add_lst_end(&fml->root, more);
			ft_putchar('-');
			ft_putstr(more->name);
			ft_putchar('\n');
			mlx_clear_window(ml.mlx, ml.win);
			paint_mlx(fml, ml);
			usleep(40500);
			return (1);
		}
	}
	return (0);
}

int			tube_between(t_salle *s1, t_salle *s2, t_frmlr *fml)
{
	int		i;

	i = 0;
	if (ft_strcmp(s1->name, s2->name) == 0)
		return (0);
	while (fml->tubes[i])
	{
		if (ft_strcmp(fml->tubes[i]->start, s1->name) == 0)
		{
			if (ft_strcmp(fml->tubes[i]->end, s2->name) == 0)
				return (1);
		}
		if (ft_strcmp(fml->tubes[i]->end, s1->name) == 0)
		{
			if (ft_strcmp(fml->tubes[i]->start, s2->name) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

t_lst		*path_test(t_frmlr *fml, t_salle *s, t_lst *r)
{
	int			i;

	i = 0;
	add_lst_end(&r, s);
	if (ft_strcmp(s->name, fml->out.name) == 0)
	{
		printf("ENNNNDDDD\n");
		return (r);
	}
	else
	{
		while (fml->salles[i])
		{
			if (tube_between(s, fml->salles[i], fml))
			{
				if (fml->salles[i]->flag == 0)
				{
					fml->salles[i]->flag = 1;
					r = path_test(fml, fml->salles[i], r);
				}
			}
			i++;
			printf("end while\n");
		}
	}
	return (r);
}
