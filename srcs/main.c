/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:08:53 by taekkim           #+#    #+#             */
/*   Updated: 2020/12/11 20:50:25 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		update_end(t_all *a)
{
	if (!a->cmd)
		return (0);
	if (a->p.end == 1)
	{
		ft_putnbr_fd(g_end, 2);
		ft_putendl_fd(": command not found", 2);
		g_end = 127;
		a->p.end = 0;
		return (0);
	}
	g_end = -1;
	return (1);
}

void	sig_handle(int signo)
{
	int state;
	int res;

	if ((res = wait(&state)) > 0)
	{
		if (signo == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_end = 130;
		}
		else if (signo == SIGQUIT)
		{
			ft_putendl_fd("Quit", 1);
			g_end = 131;
		}
		return ;
	}
	if (signo == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		ft_putstr_fd(INIT, 1);
		g_end = 130;
	}
	else if (signo == SIGQUIT)
		ft_erase();
}

void	update_pwd(t_all *a)
{
	char	tmp[1024];
	int		i;
	int		j;

	if (!a->cd)
		return ;
	i = find_row(a->env, "OLDPWD");
	if ((j = find_row(a->env, "PWD")) == -1)
	{
		if (cmd_itself(a->env[i], "OLDPWD"))
		{
			free(a->env[i]);
			a->env[i] = ft_strdup("OLDPWD");
		}
		return ;
	}
	ft_free(a->env[i]);
	a->env[i] = ft_strjoin("OLD", a->env[j]);
	ft_free(a->env[j]);
	getcwd(tmp, 1024);
	a->env[j] = ft_strjoin("PWD=", tmp);
	a->cd = 0;
}

int		main_loop(t_all *a)
{
	parsing(a);
	if (!validate(a))
		return (g_end);
	if (!update_end(a))
		return (0);
	if (!a->cmd)
		return (-1);
	update_pwd(a);
	init_export(a, a->env);
	if (a->p.pipe)
	{
		ft_pipe(a);
		return (g_end);
	}
	redirect(a);
	cmd_builtin(a);
	cmd_exec(a);
	if (a->p.s_colon)
	{
		free_com_arg(a);
		main_loop(a);
	}
	return (g_end);
}

int		main(int argc, char *argv[], char *envp[])
{
	t_all	*a;

	a = malloc(sizeof(t_all));
	signal(SIGINT, sig_handle);
	signal(SIGQUIT, sig_handle);
	init_struct(a);
	init_env(envp, a);
	while (show_prompt() && get_next_line(0, &(a->line)) > 0)
	{
		if (!a->line[0])
		{
			ft_free(a->line);
			g_end = 127;
			continue;
		}
		init(a);
		main_loop(a);
		free_com_arg(a);
		if (a->redirect)
			dup2(a->fd_tmp, a->fileno);
	}
	ft_putendl_fd("exit", 2);
	return ((int)(argc || argv));
}
