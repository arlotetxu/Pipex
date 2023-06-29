/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:37:18 by jflorido          #+#    #+#             */
/*   Updated: 2023/06/23 13:37:18 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
 * Funcion para liberar memoria
 */
void	ft_free(char **str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str[i]);
	free(str);
	free(str2);
}

/*
 * Funcion para escribir los mensajes de error
 */
int	ft_error_msg(char *message)
{
	if (1)
	{
		write(0, "\033[31m", 6);
		write(0, message, ft_strlen(message));
		write(0, "\033[0m", 5);
	}
	return (0);
}

/*
 * Funcion para generar la escritura en el pipe en el primer hijo
 */
void	ft_f_son(int *fd, char **argv, char **env, struct s_paths t_path)
{
	char	*cmd_path_com;
	int		input_f;

	close(fd[READ_END]);
	if (t_path.cmd_path == NULL)
		return ;
	cmd_path_com = ft_strjoin(t_path.cmd_path, t_path.cmd_args[0]);
	input_f = open(argv[1], O_RDONLY);
	if (input_f == -1)
	{
		ft_error_msg("Error.\nNot possible to read from the input file\n");
		return ;
	}
	dup2(fd[WRITE_END], STDOUT_FILENO);
	dup2(input_f, STDIN_FILENO);
	close(fd[WRITE_END]);
	execve(cmd_path_com, t_path.cmd_args, env);
}

/*
 *
 */
void	ft_father(int *fd, char **argv, char **env, struct s_paths t_path)
{
	char	*cmd_path_com;
	int		output_f;

	wait(NULL);
	close(fd[WRITE_END]);
	if (t_path.cmd_path == NULL)
		return ;
	cmd_path_com = ft_strjoin(t_path.cmd_path, t_path.cmd_args[0]);
	output_f = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH);
	if (output_f == -1)
	{
		ft_error_msg("Error.\nNot possible to create the output\n");
		return ;
	}
	dup2(output_f, STDOUT_FILENO);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	execve(cmd_path_com, t_path.cmd_args, env);
}
