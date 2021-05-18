/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_user_group.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:05:57 by baylak            #+#    #+#             */
/*   Updated: 2021/05/16 14:28:40 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_user_group(struct stat buf)
{
	struct passwd	*passd;
	struct group	*group;

	passd = getpwuid(buf.st_uid);
	group = getgrgid(buf.st_gid);
	ft_printf("%2d", buf.st_nlink);
	ft_printf(" %3s ", passd->pw_name);
	ft_printf("%3s ", group->gr_name);
}
