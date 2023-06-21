/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:43:32 by jflorido          #+#    #+#             */
/*   Updated: 2023/06/19 19:22:51 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define READ_END		0
#define WRITE_END	1
#define FILE_NAME	"pipex.txt"

/*
 * Funcion que guarda en un archivo lo que sale del printf
 */
void	ft_dup2(void)
{
	int file;

	file = open("testing.txt", O_WRONLY, O_CREAT);
	dup2(file, STDOUT_FILENO);
	printf("Hola Mundo a un archivo!!\n");
}

int	main(void)
{
	int	fd1[2], fd2;
	int wait_, pid;

	pipe(fd1);	//CREACION DEL PIPE
	pid = fork();
	if (pid == 0)					//primer hijo
	{
		//CERRAMOS EL INDICE DE LECTURA YA QUE NO SE NECESITA EN ESTE EXTREMO DEL PIPE
		close(fd1[READ_END]);
		//REDIRIGIMOS LA SALIDA DE PANTALLA AL FILE DESCRIPTOR DE ESCRITURA - 1 -
		dup2(fd1[WRITE_END], STDOUT_FILENO);
		//CERRAMOS EL INDICE DE ESCRITURA QUE YA NO SE NECESITA. ¿Por la redireccion?
		close(fd1[WRITE_END]);
		//EJECUTAMOS EL PRIMER COMANDO (ls -l) CON LA FUNCION execlp
		execlp("/bin/ls", "ls", "-la", NULL);
	}
	else							//volvemos al padre
	{
		//CERRAMOS EL INDICE DE ESCRITURA EN EL PADRE YA QUE NO LO NECESITA EL SEGUNDO HIJO
		close(fd1[WRITE_END]);
		pid = fork();
		if (pid == 0)				//segundo hijo
		{
			fd2 = open(FILE_NAME, O_WRONLY);
			if (fd2 == -1)
				return(0);
			//REDIRIGIMOS EL INPUT DE STDIN_FILENO AL FILE DESCRIPTOR DE LECTURA
			dup2(fd1[READ_END], STDIN_FILENO);
			//CERRAMOS EL INDICE DE LECTURA
			close(fd1[READ_END]);
			//REDIRIGIMOS LA SALIDA DE PANTALLA AL FILE DESCRIPTOR DEL ARCHIVO QUE GUARDA LA INFO
			dup2(fd2, STDOUT_FILENO);
			//EJECUTAMOS EL SEGUNDO COMANDO
			execlp("/usr/bin/wc", "wc", NULL);
		}
		else
			//CERRAMOS EL INDICE DE LECTURA DEL PADRE QUE YA NO SE NECESITA
			close(fd1[READ_END]);
	}
	//METER LOS WAITS PARA CADA UNO DE LOS HIJOS
	wait(&wait_);
	wait(&wait_);
	return (0);
}
