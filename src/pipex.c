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
 * #FT_LAUNCH_F_SON
 * 		The function launches the function ft_f_son where all the actions are
 * 		performed. Firstly, it stores in the variables the command and its
 * 		arguments (t_path.cmd_args) and the route to the path where the argument
 * 		is (t_path.cmd_path).
 *
 * #PARAMETER
 * 		- int *fd -> int array of the pipe.
 * 		- char **argv -> Input arguments.
 * 		- t_gen_p *general --> environment variables.
 *
 * #RETURN
 *
 */
void	ft_launch_f_son(int *fd, char **argv, char **env)
{
	t_path	p_data;

	p_data.cmd_args = ft_get_cmd_args(argv[2]);
	p_data.cmd_path = ft_where_is(p_data.cmd_args[0], env);
	ft_f_son(fd, argv, env, p_data);
}

/*
 * #FT_LAUNCH_FATHER
 * 		The function launches the function ft_father where all the actions are
 * 		performed in the father process. Firstly, it stores in the variables
 * 		the command and its arguments (t_path.cmd_args)
 * 		and the route to the path where the argument is (t_path.cmd_path).
 *
 * #PARAMETER
 * 		- int *fd -> int array of the pipe.
 * 		- char **argv -> Input arguments.
 * 		- t_gen_p *general --> environment variables.
 *
 * #RETURN
 *
 */
void	ft_launch_father(int *fd, char **argv, char **env)
{
	t_path	p_data;

	p_data.cmd_args = ft_get_cmd_args(argv[3]);
	p_data.cmd_path = ft_where_is(p_data.cmd_args[0], env);
	ft_father(fd, argv, env, p_data);
	ft_free(p_data.cmd_args);
	free(p_data.cmd_path);
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
