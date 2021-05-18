/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_extend_attr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:09:34 by baylak            #+#    #+#             */
/*   Updated: 2021/05/16 20:44:23 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

ssize_t	check_xattr(ssize_t xattr)
{
	if (xattr < 0)
		return (0);
	else
		return (xattr);
}

void	display_ext_attr(char *path)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t		xattr;
	char		chr;

	acl = NULL;
	xattr = 0;
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	xattr = check_xattr(xattr);
	if (xattr > 0)
		chr = '@';
	else if (acl != NULL)
		chr = '+';
	else
		chr = ' ';
	ft_printf("%c ", chr);
}
