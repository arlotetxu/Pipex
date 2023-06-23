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
 * ----------------- PENDIENTE --------------------
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
 * 	----------------- ESTRUCTURA -------------------
 * 	1 - Crear primer hijo (funcion)
 */

#include "../inc/pipex.h"

int main(int argc, char **argv, char **env)
{
	int	fd[2];
	int pid;

	if (argc == 2)
	{
		//printf("Entro en la funcion ppal.\n");
		//GENERAMOS EL PIPE
		pipe(fd);
		//CREAMOS EL PRIMER HIJO
		pid = fork();
		if (pid == -1)
			return(perror("Error\n. Cannot create the first child"), 0);
		//Funcion para gestionar el primer hijo
		if (pid == 0)
		{
			ft_f_son(fd, argv[1], env);
		}
	}
	return (0);
}