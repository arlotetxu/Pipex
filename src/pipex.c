/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:06:23 by jflorido          #+#    #+#             */
/*   Updated: 2023/06/23 13:07:00 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
 *
 */
void	ft_launch_f_son(int *fd, char **argv, char **env)
{
	struct s_paths	t_path;

	t_path.cmd_args = ft_get_cmd_args(argv[2]);
	t_path.cmd_path = ft_where_is(t_path.cmd_args[0], env);
	ft_f_son(fd, argv, env, t_path);
	ft_free(t_path.cmd_args, t_path.cmd_path);
}

/*
 *
 */
void	ft_launch_father(int *fd, char **argv, char **env)
{
	struct s_paths	t_path;

	t_path.cmd_args = ft_get_cmd_args(argv[3]);
	t_path.cmd_path = ft_where_is(t_path.cmd_args[0], env);
	ft_father(fd, argv, env, t_path);
	ft_free(t_path.cmd_args, t_path.cmd_path);
}

int	main(int argc, char **argv, char **env)
{
	int				fd[2];
	pid_t			pid;

	if (argc == 5)
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
			return (ft_error_msg("Error\n.Cannot create the first child.\n"), 0);
		if (pid == 0)
			ft_launch_f_son(fd, argv, env);
		else
			ft_launch_father(fd, argv, env);
	}
	else
		return (ft_error_msg("Error.\nInvalid number of arguments.\n"), 0);
	return (0);
}
