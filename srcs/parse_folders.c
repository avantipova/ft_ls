/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_folders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 00:15:27 by baylak            #+#    #+#             */
/*   Updated: 2021/05/16 14:44:06 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse_folders(int argc, char **argv, int arg_num_name, t_dir *dir)
{
	int	i;

	dir->count = argc - arg_num_name;
	dir->name_dir = (char **)malloc(sizeof(char *) * dir->count);
	if (!dir->name_dir)
		ft_error("malloc didn't allocate");
	i = 0;
	while (arg_num_name < argc)
	{
		dir->name_dir[i] = (char *)malloc
			(sizeof(char) * (ft_strlen(argv[arg_num_name]) + 1));
		if (dir->name_dir[i] == NULL)
			ft_error("malloc didn't allocate");
		dir->name_dir[i] = ft_strcpy(dir->name_dir[i], argv[arg_num_name]);
		arg_num_name++;
		i++;
	}
}
