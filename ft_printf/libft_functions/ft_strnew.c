/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:02:10 by aagrivan          #+#    #+#             */
/*   Updated: 2021/05/18 19:50:21 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = (char *)malloc(sizeof(char) * (size + 1));
	if (!(mem))
		return (NULL);
	while (size > 0)
	{
		mem[i] = '\0';
		size--;
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
