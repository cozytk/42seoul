/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 23:45:16 by taehkim           #+#    #+#             */
/*   Updated: 2020/12/08 23:45:18 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		parse_pipe_scolon(t_all *a)
{
	if (a->p.candidate)
		add_candidate(a);
	if (a->line[a->p.i] == '|')
		a->p.pipe = 1;
	else if (a->line[a->p.i] == ';')
		a->p.s_colon = 1;
	a->p.i++;
	return (0);
}

void	parse_redirect(t_all *a)
{
	a->p.candidate = ft_strcjoin(a->p.candidate, a->line[a->p.i]);
	a->p.i++;
	if (a->line[a->p.i] == '>')
	{
		a->p.candidate = ft_strcjoin(a->p.candidate, a->line[a->p.i]);
		a->p.i++;
	}
	add_candidate(a);
	a->p.i--;
}

void	parse_quote(t_all *a)
{
	if (a->p.candidate)
		add_candidate(a);
	a->p.start = a->p.i;
	if (a->line[a->p.i] == '\'')
		s_quote_process(a);
	else if (a->line[a->p.i] == '\"')
		d_quote_process(a);
	while (is_space(a->line[a->p.i]))
		a->p.i++;
	a->p.i--;
}

void	parse_one(t_all *a)
{
	char	*env_processed;

	if (!a->p.candidate)
		return ;
	env_processed = process_env(a, a->p.candidate);
	free(a->p.candidate);
	a->p.candidate = env_processed;
	add_candidate(a);
	a->p.i += 1;
	while (ft_iswhite(a->line[a->p.i]))
		a->p.i++;
	a->p.i--;
}

int		parse_last(t_all *a)
{
	char	*env_processed;

	if (!a->p.candidate)
		return (1);
	env_processed = process_env(a, a->p.candidate);
	free(a->p.candidate);
	a->p.candidate = env_processed;
	add_candidate(a);
	return (1);
}
