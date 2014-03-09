/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 16:08:47 by jburet            #+#    #+#             */
/*   Updated: 2014/02/10 18:28:34 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	test_parse(char **t)
{
	int		i;

	i = 0;
	while (t[i])
		printf("%s\n", t[i++]);
}

void	print_struct(t_frmlr fml)
{
	int		i;

	i = 0;
	printf("Fourmiliere:\n%d fourmis pour %d salles reliees par %d tubes.\n", fml.nb_frms, fml.nb_rooms, fml.nb_tubes);
	printf("Salle de depart: %s[%d][%d]\n", fml.in.name, fml.in.crd.x, fml.in.crd.y);
	printf("Salle de fin: %s[%d][%d]\n", fml.out.name, fml.out.crd.x, fml.out.crd.y);
	printf("\nListe des salles : \n");
	while (fml.salles[i])
	{
		printf("salle %s[%d][%d]\n", fml.salles[i]->name, fml.salles[i]->crd.x, fml.salles[i]->crd.y);
		printf("contenant %d fourmis.\n", fml.salles[i]->full);
		i++;
	}
	i = 0;
	printf("\nListe des tubes\n");
	while (fml.tubes[i])
	{
		printf("tube entre [%s] et [%s]\n", fml.tubes[i]->start, fml.tubes[i]->end);
		i++;
	}
}
