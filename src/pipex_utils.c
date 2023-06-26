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
 * Funcion para generar la escritura en el pipe en el primer hijo
 */
void	ft_f_son(int *fd, char **argv, char **env)
{
	char	*cmd_path;
	char	**cmd_args;
	int 	input_f;
	int 	i = 0;

	close(fd[READ_END]);
	cmd_args = ft_get_cmd_args(argv[2]);
	cmd_path = ft_where_is(cmd_args[0], env);
	printf("=====Dentro de la funcion=====\n");
	printf("La ruta correcta 1 es: %s\n", cmd_path);
	while (cmd_path[i])
	{
		printf("Arg-[%d] cmd 1: %s\n", i, cmd_args[i]);
		i++;
	}
	input_f = open(argv[1], O_RDONLY);
	if (input_f == -1)
		printf("Error.\nNot possible to read from the input file\n"); //TODO Valorar si convertir la funcion a int para controlar la salida
	dup2(fd[WRITE_END], STDOUT_FILENO);
	dup2(input_f, STDIN_FILENO);
	close(fd[WRITE_END]);
	execve(cmd_path, cmd_args, env);
}

/*
 *
 */
void	ft_s_son(int *fd, char **argv, char **env)
{
	char	*cmd_path;
	char	**cmd_args;
	int 	output_f;

	close(fd[WRITE_END]);
	//printf("Entro en la funcion s_son0\n");
	cmd_args = ft_get_cmd_args(argv[3]);
	cmd_path = ft_where_is(cmd_args[0], env);
	//printf("La ruta 2 correcta es: %s\n", cmd_path);
	//printf("Entro en la funcion s_son1\n");
	output_f = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (output_f == -1)
		printf("Error.\nNot possible to create the output\n"); //TODO Valorar si convertir la funcion a int para controlar la salida
	//printf("Entro en la funcion s_son2\n");
	dup2(output_f, STDOUT_FILENO);
	dup2(fd[READ_END], STDIN_FILENO);
	//printf("Entro en la funcion s_son3\n");
	close(fd[READ_END]);

	execve(cmd_path, cmd_args, env);
}