/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 19:09:55 by aagrivan          #+#    #+#             */
/*   Updated: 2021/05/18 19:50:59 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(const char *str, int count)
{
	char	*cp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	cp = (char *)malloc(sizeof(char) + count + 1);
	if (!(cp))
		return (NULL);
	while (i < count)
	{
		cp[i] = str[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
