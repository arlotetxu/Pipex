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

char	*ft_get_path(char **env)
{
	//char	*path;
	int		i;

	i = 0;
	//path = NULL;
	//printf("Entro en la funcion.\n");
	while(env[i]) {
		if (ft_strncmp(env[i], "PATH", 4) == 0) {
			//printf("valor de i: %d\n", i);
			//printf("Cadena retornada: %s\n", env[i]);
			return (env[i]);
		}
		i++;
	}
	return (0);
}

char	**ft_get_path_str(char *env)
{
	char	**path_dir;
	int 	i;
	int 	j;

	path_dir = ft_split(env, ':');
	if (path_dir == NULL)
		return (NULL);
	i = 0;
	while (path_dir[i])
	{
		j = 0;
		while (path_dir[i][j] != '/')
			j++;
		// OJO, uso la ft_substr_ander.c --> Asegurarse que es la que esta en el libft
		path_dir[i] = ft_strjoin(ft_substr(path_dir[i], j,
						ft_strlen(path_dir[i]) - j + 1), "/");
		//printf("String %d: %s\n", i, path_dir[i]);
		i++;
	}
	return(path_dir);
}
