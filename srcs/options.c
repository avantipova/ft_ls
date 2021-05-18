/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:00:01 by baylak            #+#    #+#             */
/*   Updated: 2021/05/16 20:10:38 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	check_upr(t_dir *dir, char flag)
{
	if (flag == 'R')
		return (1);
	else
		return (dir->options.up_r);
}

int	check_r(t_dir *dir, char flag)
{
	if (flag == 'r')
		return (1);
	else
		return (dir->options.r);
}

int	check_t(t_dir *dir, char flag)
{
	if (flag == 't')
		return (1);
	else
		return (dir->options.t);
}
