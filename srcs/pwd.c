/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:29:26 by taekkim           #+#    #+#             */
/*   Updated: 2020/11/30 00:29:27 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int 	pwd(t_all *a)
{
	char tmp[1024];

	if (!ft_strncmp(a->cmd, "pwd\0", 4))
	{
		getcwd(tmp, 1024);
		ft_putendl_fd(tmp, 1);
		return (1);
	}
	return (0);
}

//int 	pwd(t_all *a)
//{
//	char tmp[1024];
//
//	if (!ft_strncmp(a->cmd, "pwd\0", 4))
//	{
//		getcwd(tmp, 1024);
//		ft_putendl_fd(tmp, 1);
//		return (1);
//	}
//	return (0);
//}