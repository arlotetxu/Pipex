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
 */

#include "../inc/pipex.h"

int main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		//CREAR FUNCION CON LOS CHEQUEOS Y REFERENCIARLA AQUI

		//GENERAMOS EL PIPE
		pipe(fd);
		//CREAMOS EL PRIMER HIJO
		pid = fork();
		if (pid == -1)
			return(perror("Error\n.Cannot create the first child\n"), 0);
		//Funcion para gestionar el primer hijo
		if (pid == 0)
			ft_f_son(fd, argv, env);
//		else
//		{
//			//close(fd[WRITE_END]); //Cerramos extremos de escritura del padre que ya no se necesita
//			//CREAMOS EL SEGUNDO HIJO
//			pid = fork();
//			if (pid == -1)
//				return(perror("Error\n.Cannot create the second child\n"), 0);
//			if (pid == 0)
//				ft_s_son(fd, argv, env);
//			else
//				close(fd[READ_END]);
//		}

	}
	else
		return (printf("Error.\nInvalid number of arguments\n"), 0); //TODO sustituir printf
	wait(NULL);
	wait(NULL);
	return (0);
}