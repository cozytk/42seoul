/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 23:05:17 by taekkim           #+#    #+#             */
/*   Updated: 2020/11/29 23:05:18 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	delete_env(char **mat, t_all *a, int i, int j)
{
	while (mat[++i])
	{
		j = -1;
		while (a->env[++j])
		{
			if (same_key(a->env[j], mat[i]))
			{
				a->env = ft_delete_row(a->env, j);
				break ;
			}
		}
		j = -1;
		while (a->sub_env && a->sub_env[++j])
		{
			if (same_key(a->sub_env[j], mat[i]))
			{
				a->sub_env = ft_delete_row(a->sub_env, j);
				break ;
			}
		}
		if (!a->env[j] && has_identifier(mat[i]))
			write_error("unset", mat[i], ": not a valid identifier", 1);
	}
}

void	parse_unset(t_all *a)
{
	a->arg = check_overlap(a->arg);
	delete_env(a->arg, a, -1, -1);
	ft_free_mat(a->arg);
	a->arg = NULL;
}

int		unset(t_all *a)
{
	if (!ft_strncmp(a->cmd, "unset\0", 6))
	{
		if (!a->arg)
			return (1);
		parse_unset(a);
		ft_free_mat(a->ept);
		a->ept = NULL;
		init_export(a, a->env);
		return (1);
	}
	return (0);
}
