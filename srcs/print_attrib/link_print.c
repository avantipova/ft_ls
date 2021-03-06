/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:04:21 by baylak            #+#    #+#             */
/*   Updated: 2021/05/16 19:54:44 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	link_print(char *path, char *file_name, mode_t mode)
{
	char		buf[1024];
	ssize_t		len;

	if ((mode & S_IFMT) == S_IFLNK)
	{
		ft_bzero(buf, 1024);
		len = readlink(path, buf, sizeof(buf));
		if (len < 0)
		{
			perror("readlink");
			exit(EXIT_FAILURE);
		}
		ft_printf(" %s -> %s\n", file_name, buf);
	}
	else
		ft_printf(" %s\n", file_name);
}
