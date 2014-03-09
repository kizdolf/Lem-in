/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 14:25:38 by jburet            #+#    #+#             */
/*   Updated: 2014/02/12 21:00:16 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_frmlr		create_frmlr(char **entry)
{
	int			i;
	t_frmlr		fml;

	i = 1;
	fml = init_fml(entry, fml);
	printf("fml.in.full = %d\n", fml.in.full);
	while (entry[i])
	{
		if (ft_strncmp(entry[i], "##", 2) == 0)
			get_special_line(entry, &fml, i++);
		else if (entry[i][0] != '#')
		{
			if (is_room(entry[i]))
				get_a_room(entry[i++], &fml);
			else
			{
				if (!get_a_tube(entry[i++], &fml))
					return (fml);
			}
		}
		else
			get_a_comment(entry[i++], &fml);
	}
	return (fml);
}

int			tube_is_room(char *s, t_frmlr fml)
{
	int		i;

	i = 0;
	while (fml.salles[i])
	{
		if (ft_strcmp(fml.salles[i++]->name, s) == 0)
			return (1);
	}
	return (0);
}

t_frmlr		verif_fml(t_frmlr fml)
{
	int		i;

	i = 0;
	while (fml.tubes[i])
	{
		if (!tube_is_room(fml.tubes[i]->start, fml) || !tube_is_room(fml.tubes[i]->end, fml))
		{
			fml.tubes[i] = NULL;
			fml.nb_tubes = i;
		}
		i++;
	}
	return (fml);
}

t_frmlr		init_lemin(void)
{
	char	**entry;
	t_frmlr	fml;

	entry = parse_stdin();
	fml = create_frmlr(entry);
	fml = verif_fml(fml);
	fml.salles = init_flags_rooms(fml.salles);
	return (fml);
}

int			main(void)
{
	t_frmlr	fml;
	int		paths;
	int		i;
	t_mlx	ml;
	t_lst	*root;

	fml = init_lemin();
	i = 0;
	//print_struct(fml);
	ml.mlx = mlx_init();
	ml.win = mlx_new_window(ml.mlx, HEIGHT, WIDTH, "Lem In");
	paint_mlx(&fml, ml);
	fml.in.flag = 0;
	fml.out.flag = 0;

		printf("ici\n");
		root = new_lst();
		add_lst_end(&root, &fml.in);
		fml.root = root;
		//paths = path(&fml.in, &fml.out, &fml, 0, i++, ml);
		fml.root = path_test(&fml, &fml.in, fml.root);
		printf("LOL\n");
		if (paths == 0)
			return (1);
//		print_lst(fml.root);
		printf("\nboucle\n");

	return (0);
}
