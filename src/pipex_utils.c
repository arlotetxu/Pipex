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
 * Funcion para determinar la ruta del comando 1
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
		{
			//printf("La ruta correcta es: %s\n", path_arr[i]);
			return(path_arr[i]);
		}
		i++;
	}
	return (NULL);
}

/*
 * Funcion para generar la escritura en el pipe en el primer hijo
 */
void	ft_f_son(int *fd, char *cmd, char **env)
{
	char	*cmd_path;

	printf("FD: %d\n", fd[0]);
	cmd_path = ft_where_is(cmd, env);
//	close(fd[READ_END]);
//	dup2(fd[WRITE_END], STDOUT_FILENO);
//	close(fd[WRITE_END]);
	printf("La ruta correcta es: %s\n", cmd_path);
	//AQUI IRIA LA FUNCION execve
}