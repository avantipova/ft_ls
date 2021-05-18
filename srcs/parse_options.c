/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:27:32 by baylak            #+#    #+#             */
/*   Updated: 2021/05/18 21:08:42 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	check_a(t_dir *dir, char flag)
{
	if (flag == 'a')
		return (1);
	else
		return (dir->options.a);
}

int	check_l(t_dir *dir, char flag)
{
	if (flag == 'l')
		return (1);
	else
		return (dir->options.l);
}

void	insert_options(t_dir *dir, char flag)
{
	dir->options.a = check_a(dir, flag);
	dir->options.l = check_l(dir, flag);
	dir->options.up_r = check_upr(dir, flag);
	dir->options.r = check_r(dir, flag);
	dir->options.t = check_t(dir, flag);
}

int	parse_options_body(t_dir *dir, char **argv, int i, int argc)
{
	size_t	j;

	if (ft_strcmp(argv[i], "-") == 0 && i == (argc - 1))
	{
		ft_printf("./ft_ls: %s: No such file or directory\n", argv[i]);
		exit(0);
	}
	if (ft_strcmp(argv[i], "-") == 0)
	{
		ft_printf("./ft_ls: %s: No such file or directory\n", argv[i]);
		return (++i);
	}
	if (argv[i][0] == '-' && argv[i][1])
	{
		j = 0;
		while (++j < ft_strlen(argv[i]))
		{
			if (argv[i][j] == 'a' || argv[i][j] == 'R' ||
				argv[i][j] == 'r' || argv[i][j] == 't' || argv[i][j] == 'l')
				insert_options(dir, argv[i][j]);
			else
				print_usage(argv[i][j]);
		}
	}
	else if (argv[i][0] != '-' || argv[1][0] != '-')
		return (i);
	return (0);
}

int	parse_options(t_dir *dir, int argc, char **argv)
{
	size_t	i;
	size_t	j;
	int		arg_num_name;

	i = 0;
	j = 0;
	while (i < (size_t)argc)
	{
		arg_num_name = parse_options_body(dir, argv, i, argc);
		if (arg_num_name > 0)
			return (arg_num_name);
		i++;
	}
	return (0);
}
