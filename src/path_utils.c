/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:56:20 by jflorido          #+#    #+#             */
/*   Updated: 2023/06/23 14:56:20 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
 * Funcion para sacar la cadena de texto de PATH del env
 */
char	*ft_get_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			return (env[i]);
		i++;
	}
	return (0);
}

/*
 * Funcion para exportar a un char** las diferentes cadenas de PATH
 * 	(separacion ':'
 * Ademas de eso, añadimos '/' al final de las cadenas para sacar
 * 	las rutas completas
 */
char	**ft_get_path_str(char *env)
{
	char	**path_dir;
	int		i;
	int		j;

	path_dir = ft_split(env, ':');
	if (path_dir == NULL)
		return (NULL);
	i = 0;
	while (path_dir[i])
	{
		j = 0;
		while (path_dir[i][j] != '/')
			j++;
		path_dir[i] = ft_strjoin(ft_substr(path_dir[i], j,
					ft_strlen(path_dir[i]) - j + 1), "/");
		i++;
	}
	return (path_dir);
}

/*
 * Funcion para determinar la ruta del los comandos
 */
char	*ft_where_is(char *cmd, char **env)
{
	char	**path_arr;
	int		i;

	i = 0;
	path_arr = ft_get_path_str(ft_get_path(env));
	while (path_arr[i])
	{
		if (access (ft_strjoin(path_arr[i], cmd), F_OK) == 0)
			return (path_arr[i]);
		i++;
	}
	ft_error_msg("Error.\nNot possible to locate the command.\n");
	return (NULL);
}

/*
 * Funcion que guarda en un char** el comando y sus argumentos
 */
char	**ft_get_cmd_args(char *argv)
{
	char	**cmd_args;

	cmd_args = NULL;
	cmd_args = ft_split(argv, ' ');
	return (cmd_args);
}
