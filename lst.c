/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 12:19:01 by jburet            #+#    #+#             */
/*   Updated: 2014/02/12 13:34:33 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_lst		*new_lst(void)
{
	t_lst	*root;

	root = (t_lst *)ft_memalloc(sizeof(t_lst));
	root->room = NULL;
	root->pos = 0;
	root->next = NULL;
	root->prev = NULL;
	return (root);
}

void		add_lst_end(t_lst **root, t_salle *s)
{
	int		pos;
	t_lst	*elem;

	elem = new_lst();
	pos = 0;
	while ((*root)->next)
	{
		pos++;
		(*root) = (*root)->next;
	}
	elem->pos = pos;
	elem->room = (t_salle *)ft_memalloc(sizeof(t_salle));
	elem->room = s;
	printf("%s(%d)[%d]->", elem->room->name, elem->room->flag, elem->pos);
	elem->prev = (*root);
	elem->next = NULL;
	(*root)->next = elem;
}

t_salle		**init_flags_rooms(t_salle **s)
{
	int		i;

	i = 0;
	while (s[i])
		s[i++]->flag = 0;
	return (s);
}

void		print_lst(t_lst *root)
{
	printf("la\n");
	while (root->prev)
		root = root->prev;
	printf("ici\n");
	while (root->next)
	{
		printf("%s[%d]->", root->room->name, root->pos);
		root = root->next;
	}
}