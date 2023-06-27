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
void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str[i]);
	free(str);
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
void	ft_f_son(int *fd, char **argv, char **env, char *cmd_path, char **cmd_args)
{
	char	*cmd_path_com;
	int 	input_f;

	close(fd[READ_END]);
	cmd_path_com = ft_strjoin(cmd_path, cmd_args[0]);
	//printf("Path a buscar en evecve 1 hijo: %s\n", cmd_path_com);
	input_f = open(argv[1], O_RDONLY);
	if (input_f == -1)
		ft_error_msg("Error.\nNot possible to read from the input file\n");
	dup2(fd[WRITE_END], STDOUT_FILENO);
	dup2(input_f, STDIN_FILENO);
	close(fd[WRITE_END]);
	execve(cmd_path_com, cmd_args, env);
}

/*
 *
 */
void	ft_s_son(int *fd, char **argv, char **env, char *cmd_path, char **cmd_args)
{
	char	*cmd_path_com;
	int 	output_f;

	close(fd[WRITE_END]);
	cmd_path_com = ft_strjoin(cmd_path, cmd_args[0]);
	//printf("Path a buscar en evecve 2 hijo: %s\n", cmd_path_com);
	output_f = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (output_f == -1)
		ft_error_msg("Error.\nNot possible to create the output\n");
	dup2(output_f, STDOUT_FILENO);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	execve(cmd_path_com, cmd_args, env);
}