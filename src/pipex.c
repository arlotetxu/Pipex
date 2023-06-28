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

/*
 * ----------------- CHEQUEOS --------------------
 * # CHEQUEOS DE ENTRADA
 * 		- Numero de argumentos?
 * 		- Argumentos validos
 * 			- Archivo inicial existe?
 * 			- Comando 1 y 2 existen dentro del array de directorios del path (access).
 * 				Devolver path si es OK, si no 0
 * 			- Fichero donde escribir la salida final
 * 		- OJO a como nos dan los argumentos. Pueden ser separados o todos juntos???
 *
 *
 * 	----------------- PENDIENTE -------------------
 * # Chequeos de entrada.
 * # Finalizar los pasos del primer hijo.
 * 		- Cuidado con la funcion execve... Necesita un char** con los argumentos del primer comando.
 * 			Necesario hacer split de cada ARGV para pasarselo como argumento.
 *
 * 	#liberar memoria - funciones con ft_split
 */

#include "../inc/pipex.h"

int main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	char *cmd_path;
	char **cmd_args;
//	int i = 0;

	if (argc == 5)
	{
		//CREAR FUNCION CON LOS CHEQUEOS Y REFERENCIARLA AQUI

		//GENERAMOS EL PIPE
		pipe(fd);
		//CREAMOS EL PRIMER HIJO
		pid = fork();
		if (pid == -1)
		{
			ft_error_msg("Error\n.Cannot create the first child\n");
			return (0);
		}
		//Funcion para gestionar el primer hijo
		if (pid == 0)
		{
			cmd_args = ft_get_cmd_args(argv[2]);
			cmd_path = ft_where_is(cmd_args[0], env);
			if (cmd_path == NULL)
				return (0);
//			printf("CMD_PATH 1: %s\n", cmd_path);
//			while (cmd_args[i])
//			{
//				printf("CMD_ARGS1-[%d]: %s\n", i, cmd_args[i]);
//				i++;
//			}
			ft_f_son(fd, argv, env, cmd_path, cmd_args);
			ft_free(cmd_args);
			free(cmd_path);
		}
		else
		{
			//i = 0;
			//waitpid(pid, NULL, 0);
			wait(NULL);
			cmd_args = ft_get_cmd_args(argv[3]);
			cmd_path = ft_where_is(cmd_args[0], env);
			if (cmd_path == NULL)
				return (0);
//			printf("CMD_PATH 2: %s\n", cmd_path);
//			while (cmd_args[i])
//			{
//				printf("CMD_ARGS2-[%d]: %s\n", i, cmd_args[i]);
//				i++;
//			}
			ft_s_son(fd, argv, env, cmd_path, cmd_args);
			ft_free(cmd_args);
			free(cmd_path);
		}

	}
	else
	{
		ft_error_msg("Error.\nInvalid number of arguments\n");
		return (0);
	}
//	wait(NULL);
//	wait(NULL);
	return (0);
}