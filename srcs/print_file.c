/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:48:52 by baylak            #+#    #+#             */
/*   Updated: 2020/08/29 12:09:15 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file(t_files *list, t_dir *dir)
{
	if (dir->options.l)
		display_attr(list->name, list->name, list->mystat.st_mode);
	else
		ft_printf("%s\n", list->name);
}
