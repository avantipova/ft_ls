/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:08:57 by baylak            #+#    #+#             */
/*   Updated: 2021/05/16 14:29:25 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_time(time_t mtime)
{
	char	*str_time;
	time_t	ct;

	ct = time(NULL);
	str_time = ctime(&mtime);
	if (str_time == NULL)
		return ;
	ft_printf("%3.3s ", str_time + 4);
	ft_printf("%2.2s ", str_time + 8);
	if (mtime < 15778800 || mtime > ct)
		ft_printf("%5.4s ", str_time + 20);
	else
		ft_printf("%5.5s ", str_time + 11);
}
