/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 18:57:02 by jburet            #+#    #+#             */
/*   Updated: 2014/02/10 19:29:55 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

t_crd		*atrib_pix(t_lne *line)
{
	t_crd	*lne;

	lne = malloc(sizeof(t_crd));
	if ((lne->x = line->x) > WIDTH)
		lne->x = WIDTH;
	if ((lne->y = line->y) > HEIGHT)
		lne->y = HEIGHT;
	if ((lne->x = line->x) < 0)
		lne->x = 0;
	if ((lne->y = line->y) < 0)
		lne->y = 0;
	return (lne);
}

void	draw_one(t_lne *line, t_mlx ml)
{
	int		i;
	int		erreur;
	t_crd	**lne;

	erreur = line->dx / 2;
	i = 0;
	lne = (t_crd **)malloc(sizeof(t_crd *) * line->dx);
	while (i < line->dx)
	{
		line->x += line->x_incr;
		erreur += line->dy;
		if (erreur > line->dx)
		{
			erreur -= line->dx;
			line->y += line->y_incr;
		}
		lne[i] = atrib_pix(line);
		mlx_pixel_put(ml.mlx, ml.win, lne[i]->x, lne[i]->y, COLOR_SQUARE);
		i++;
	}
}

void	draw_two(t_lne *line, t_mlx ml)
{
	int		i;
	int		erreur;
	t_crd	**lne;

	erreur = line->dy / 2;
	i = 0;
	lne = (t_crd **)malloc(sizeof(t_crd *) * line->dy);
	while (i < line->dy)
	{
		line->y += line->y_incr;
		erreur += line->dx;
		if (erreur > line->dy)
		{
			erreur -= line->dy;
			line->x += line->x_incr;
		}
		lne[i] = atrib_pix(line);
		mlx_pixel_put(ml.mlx, ml.win, lne[i]->x, lne[i]->y, COLOR_SQUARE);
		i++;
	}
}

void	line(t_crd *pt1, t_crd *pt2, t_mlx ml)
{
	t_lne	lne;

	lne.dx = ft_abs(pt2->x - pt1->x);
	lne.dy = ft_abs(pt2->y - pt1->y);
	lne.x = pt1->x;
	lne.y = pt1->y;
	if (pt1->x < pt2->x)
		lne.x_incr = 1;
	else
		lne.x_incr = -1;
	if (pt1->y < pt2->y)
		lne.y_incr = 1;
	else
		lne.y_incr = -1;
	if (lne.dx > lne.dy)
		draw_one(&lne, ml);
	else
		draw_two(&lne, ml);
}

void		draw_square(int x, int y, int dim, t_mlx ml, int nb, int color)
{
	int		i;
	int		j;

	i = x + dim;
	j = y + dim;
	while (x < i)
		mlx_pixel_put(ml.mlx, ml.win, x++, y, color);
	while (y < j)
		mlx_pixel_put(ml.mlx, ml.win, x, y++, color);
	i = x - dim;
	while (i < x)
		mlx_pixel_put(ml.mlx, ml.win, i++, y, color);
	j = y - dim;
	x = x - dim;
	while (j < y)
		mlx_pixel_put(ml.mlx, ml.win, x, j++, color);
	x += 4;
	y -= 4;
	if (nb)
		draw_square(x, y, 2, ml, nb - 1, COLOR_FOURMI);
}

void		draw_line(t_tube *t, t_frmlr *fml, t_mlx ml)
{
	t_salle		*s;
	t_crd		a;
	t_crd		b;
	s = get_salle_from_tube(t, fml, 1);
	a.x = s->crd.x * 30 + 25;
	a.y = s->crd.y * 30 + 25;
	s = get_salle_from_tube(t, fml, 2);
	b.x = s->crd.x * 30 + 25;
	b.y = s->crd.y * 30 + 25;
	line(&a, &b, ml);
}

void		paint_mlx(t_frmlr *fml, t_mlx ml)
{
	int		i;

	i = 0;
	while(fml->salles[i])
	{
		draw_square(fml->salles[i]->crd.x * 30, fml->salles[i]->crd.y * 30, SIZE_ROOM, ml, fml->salles[i]->full, COLOR_SQUARE);
		mlx_string_put(ml.mlx, ml.win, fml->salles[i]->crd.x * 30 + 5, fml->salles[i]->crd.y * 30 + 15, COLOR_SQUARE, fml->salles[i]->name);
		i++;
	}
	i = 0;
	while (fml->tubes[i])
		draw_line(fml->tubes[i++], fml, ml);
}
