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
 * #FT_GET_PATH
 * 		The function locates within the environment variable, the PATH route
 * 		where the UNIX functions are.
 *
 * #PARAMETER
 * 		- char **env -> environment variable
 *
 * #RETURN
 *		- env[i] -> The string with the path route.
 *		- 0 -> The path was not located.
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
 * #FT_GET_PATH_STR
 * 		The function splits all the different routes where the UNIX functions
 * 		could be. This is done using the ft_split function from libft and using
 * 		":" as string separator. Additionally, we complete the path routes
 * 		adding a '/' at the end of each string created.
 *
 * #PARAMETER
 * 		- char *env -> Complete PATH string.
 *
 * #RETURN
 *		- path_dir -> a char ** with the different path routes.
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
 * #FT_WHERE_IS
 * 		The function determines what is the right path to launch a command
 *
 * #PARAMETER
 * 		- char *cmd -> the command to search.
 * 		- char **env -> environment variable.
 *
 * #RETURN
 *		- path_arr[i] -> a char *with the right path where the command is.
 */
char	*ft_where_is(char *cmd, char **env)
{
	char	**path_arr;
	int		i;

	i = 0;
	path_arr = ft_get_path_str(ft_get_path(env));
	while (path_arr && path_arr[i] != NULL)
	{
		if (access (ft_strjoin(path_arr[i], cmd), F_OK) == 0)
			return (path_arr[i]);
		i++;
	}
	ft_error_msg("Error.\nWarning. One command could not be found!!.\n");
	return (NULL);
}

/*
 * #FT_GET_CMD_ARGS
 * 		The function gets the command arguments. The ft_split fucntion is used
 * 		to get all the arguments due to they are separated with a space.
 *
 * #PARAMETER
 * 		- char *argv -> The right argument from the input (command & arguments)
 *
 * #RETURN
 *		- cmd_args -> a char ** with all the command arguments.
 */
char	**ft_get_cmd_args(char *argv)
{
	char	**cmd_args;

	cmd_args = NULL;
	cmd_args = ft_split(argv, ' ');
	return (cmd_args);
}
