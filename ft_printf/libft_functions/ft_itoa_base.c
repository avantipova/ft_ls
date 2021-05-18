/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:31:19 by aagrivan          #+#    #+#             */
/*   Updated: 2021/05/18 19:39:50 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_length(int value, int base)
{
	int		len;

	if (value <= 0)
		len = 1;
	else
		len = 0;
	while (value)
	{
		len++;
		value /= base;
	}
	return (len);
}

long	check_nbr(int value)
{
	if (value < 0)
		return (-(long)value);
	else
		return ((long)value);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	long	nbr;
	int		len;

	if (base < 2 || base > 36)
		return (NULL);
	nbr = check_nbr(value);
	len = ft_get_length(value, base);
	str = ft_strnew(len);
	if (!(str))
		return (NULL);
	len--;
	while (nbr)
	{
		if (nbr % base < 10)
			str[len--] = (nbr % base) + '0';
		else
			str[len--] = (nbr % base) + 'a' - 10;
		nbr /= base;
	}
	if (len == 0)
		str[len] = '-';
	if (value == 0)
		str[len] = '0';
	return (str);
}
