/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:35:25 by poatmeal          #+#    #+#             */
/*   Updated: 2021/05/18 18:46:31 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_plus(t_buf *buf, t_printf *get, int i)
{
	if (get->sign < 0)
	{
		buf->wh_num[BIG_BUFF - i] = -3;
		i++;
	}
	else if (get->fp && get->sign > 0)
	{
		buf->wh_num[BIG_BUFF - i] = -5;
		i++;
	}
	return (i);
}

void	fill_width_zero(t_buf *buf, t_printf *get, int i, int n)
{
	if (get->sign < 0 || (get->fp && get->sign > 0))
		n--;
	while (i < n)
	{
		buf->wh_num[BIG_BUFF - i] = 0;
		i++;
	}
	if (!get->fp && get->fs && get->sign > 0)
		buf->wh_num[BIG_BUFF - i] = -16;
}

static int	check_n(t_printf *get, int n)
{
	if (get->f_prec != 0)
		return (n - 1);
	else
		return (n);
}

void	fill_width(t_buf *buf, t_printf *get)
{
	int		n;
	int		i;

	i = 0;
	n = get->width - get->f_prec;
	if (!get->fp && get->fs && get->sign > 0 && i < n)
		n = get->width - get->f_prec - 1;
	n = check_n(get, n);
	while (buf->wh_num[BIG_BUFF - i] != -1)
		i++;
	if (get->fz)
		fill_width_zero(buf, get, i, n);
	else
	{
		i = fill_plus(buf, get, i);
		while (i < n)
		{
			buf->wh_num[BIG_BUFF - i] = -16;
			i++;
		}
		if (!get->fp && get->fs && get->sign > 0)
			buf->wh_num[BIG_BUFF - i] = -16;
	}
}

int	check_plus_space(t_printf *get)
{
	if (get->sign < 0 && get->fz)
		return (1);
	if (get->sign < 0 && !get->fz)
	{
		ft_putchar('-');
		get->len++;
		return (1);
	}
	else if (get->fp && get->sign > 0)
	{
		ft_putchar('+');
		get->len++;
		return (1);
	}
	else if (!get->fp && get->fs && get->sign > 0)
	{
		ft_putchar(' ');
		get->len++;
		return (1);
	}
	return (0);
}
