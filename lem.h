/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 14:27:35 by jburet            #+#    #+#             */
/*   Updated: 2014/02/12 20:58:15 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H
# include "./get_next_line.h"
# include "./lib/libft.h"
# include <stdio.h>
# include <signal.h>
# include <mlx.h>
# include "/usr/X11/include/X11/X.h"

# define COLOR_SQUARE 0xF0F0F0
# define COLOR_FOURMI 0xFF0000
# define SIZE_ROOM 50
# define HEIGHT 900
# define WIDTH 900

typedef struct				s_crd
{
	int		x;
	int		y;
}							t_crd;

typedef struct				s_frm
{
	int		id;
}							t_frm;

typedef struct				s_tube
{
	char	*start;
	char	*end;
}							t_tube;

typedef struct				s_salle
{
	char	*name;
	t_crd	crd;
	int		full;
	int		flag;
	struct s_salle	**tub;
}							t_salle;

typedef struct				s_lst
{
		t_salle			*room;
		int				pos;
		struct s_lst	*next;
		struct s_lst	*prev;
}							t_lst;

typedef struct				s_frmlr
{
	t_frm		*frms;
	int			nb_frms;
	int			nb_rooms;
	int			nb_tubes;
	t_salle		**salles;
	t_tube		**tubes;
	char		**comment;
	t_salle		in;
	t_salle		out;
	int			count;
	t_lst		*root;
}							t_frmlr;

typedef struct				s_mlx
{
	void	*mlx;
	void	*win;
}							t_mlx;

typedef struct			s_lne
{
	int			dx;
	int			x_incr;
	int			dy;
	int			y_incr;
	int			x;
	int			y;
}						t_lne;



char			**parse_stdin(void);

void	test_parse(char **t);

void	print_struct(t_frmlr fml);

int				is_room(char *line);

int				is_tube(char *line);

int				nb_rooms(char **entry);

int				nb_tubes(char **entry);

int				nb_comment(char **entry);

void			get_special_line(char **entry, t_frmlr *fml, int num);

void			get_a_room(char *line, t_frmlr *fml);

int				get_a_tube(char *line, t_frmlr *fml);

void			get_a_comment(char *line, t_frmlr *fml);

t_frmlr			init_fml(char **entry, t_frmlr fml);

int				path(t_salle *in, t_salle *out, t_frmlr *fml, int i, int frm, t_mlx ml);

int				all_path(t_salle *in, t_salle *out, t_frmlr *fml, char **path);

void			paint_mlx(t_frmlr *fml, t_mlx ml);

t_salle			*get_salle_from_tube(t_tube *tube, t_frmlr *fml, int choice);

t_salle			**init_flags_rooms(t_salle **s);

void			add_lst_end(t_lst **root, t_salle *s);

t_lst			*new_lst(void);

void			print_lst(t_lst *root);

t_lst			*path_test(t_frmlr *fml, t_salle *s, t_lst *r);

#endif
