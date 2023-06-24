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
 * Funcion que guarda en un char** el comando y sus argumentos
 */
char	**ft_get_cmd_args(char *argv)
{
	char	**cmd_args;
	int 	i = 0;

	cmd_args = NULL;
	argv = ft_strjoin(argv, " NULL");
	cmd_args = ft_split(argv, ' ');
	while (cmd_args[i])
	{
		printf("cmd_args[%d]: %s\n", i, cmd_args[i]);
		i++;
	}
	return (cmd_args);
}

/*
 * Funcion para determinar la ruta del los comandos
 */
char	*ft_where_is(char *cmd, char **env)
{
	char	**path_arr;
	int 	i;

	i = 0;
	path_arr =ft_get_path_str(ft_get_path(env));
	while (path_arr[i])
	{
		if(access(ft_strjoin(path_arr[i],cmd),F_OK) == 0)
			//printf("La ruta correcta es: %s\n", path_arr[i]);
			return(path_arr[i]);
		i++;
	}
	return (NULL);
}

/*
 * Funcion para generar la escritura en el pipe en el primer hijo
 */
void	ft_f_son(int *fd, char **argv, char **env)
{
	char	*cmd_path;
	char	**cmd_args;

	printf("FD: %d\n", fd[0]); // Linea a borrar cuando se complete la funcion
	cmd_args = ft_get_cmd_args(argv[1]);
	//cmd_path = ft_where_is(argv[1], env);
	cmd_path = ft_where_is(cmd_args[1], env);
//	close(fd[READ_END]);
//	dup2(fd[WRITE_END], STDOUT_FILENO);
//	close(fd[WRITE_END]);
	printf("La ruta correcta es: %s\n", cmd_path);
	/*AQUI IRIA LA FUNCION execve. Ojo, tiene como segundo argumento un argv que
	 * corresponde con el comando y los flags del mismo. Tenemos que hacer una funcion
	 * que haga split a los argumentos
	 * char *args[] = {"ls", "-l", NULL};
	 * execve("/bin/ls", args, NULL);
	 */
	//ft_get_cmd_args(argv);
}