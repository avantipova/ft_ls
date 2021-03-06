/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:19:38 by Student           #+#    #+#             */
/*   Updated: 2021/05/16 20:13:21 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <pwd.h>
# include "libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include "limits.h"
# include <time.h>

typedef struct s_options
{
	int				l;
	int				up_r;
	int				a;
	int				r;
	int				t;
}					t_options;

typedef struct s_files
{
	struct s_files	*next;
	struct s_files	*prev;
	char			*name;
	char			*file_name;
	struct stat		mystat;
}					t_files;

typedef struct s_dir
{
	char			**name_dir;
	t_options		options;
	t_files			*files;
	int				arg_num_name;
	DIR				*dirp;
	struct dirent	*dp;
	int				count;
	int				is_dir;
}					t_dir;

int					parse_options(t_dir	*dir, int argc, char **argv);
void				print_usage(char str);
void				parse_folders(int argc, char **argv,
						int arg_num_name, t_dir *dir);
void				init_options(t_dir *dir);
t_files				*init_list_name(t_dir *dir);
void				swap(t_files *a, t_files *b);
int					check_upr(t_dir *dir, char flag);
int					check_r(t_dir *dir, char flag);
int					check_t(t_dir *dir, char flag);

t_files				*init_list(t_files *head, char *name);
t_files				*add_elem(t_files *head, char *name);
void				insert_t_files(t_files **head_ptr, t_files *files);
void				reverse_list(t_files **head);

t_files				*sort_time(t_files *path);
void				quicksort(t_files *head);

void				print_total(t_files *file);
void				print_file_type(struct stat buf);
void				print_own_rights(struct stat buf);
void				print_group_per(struct stat buf);
void				print_peop_rights(struct stat buf);
void				display_ext_attr(char *path);
void				print_user_group(struct stat buf);
char				*add_valid_path(char *path, char *add);
void				print_dir(t_files *list, t_dir *dir, int flag);
void				print_file(t_files *list, t_dir *dir);
void				display_attr(char *name, char *file_name, mode_t mode);
void				dir_content(t_files *list, t_dir *dir);
void				print_time(time_t mtime);
void				link_print(char *path, char *file_name, mode_t mode);

void				ft_clear_list(t_files **head);
void				ft_clear_dir(char **dir);

#endif
