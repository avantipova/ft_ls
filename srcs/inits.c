/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:34:28 by baylak            #+#    #+#             */
/*   Updated: 2021/05/16 14:25:23 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_options(t_dir *dir)
{
	dir->options.a = 0;
	dir->options.l = 0;
	dir->options.up_r = 0;
	dir->options.r = 0;
	dir->options.t = 0;
}

t_files	*init_list_name(t_dir *dir)
{
	t_files	*list;
	int		i;
	char	*tmp;

	list = NULL;
	i = -1;
	if (!dir)
		return (NULL);
	if (dir->count == 0)
	{
		list = add_elem(list, ".");
		return (list);
	}
	while (++i < dir->count)
	{
		tmp = dir->name_dir[i];
		list = add_elem(list, tmp);
		free(dir->name_dir[i]);
		dir->name_dir[i] = NULL;
	}
	free(dir->name_dir);
	dir->name_dir = NULL;
	return (list);
}
