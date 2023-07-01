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
 * #FT_FREE
 * 		The function frees al the mallocs done (specially with ft_split function)
 *
 * #PARAMETER
 * 		- char **str -> a char array.
 * 		- char **env -> environment variable.
 *
 * #RETURN
 *		-
 */
void	ft_free(char **str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str[i]);
	free(str);
	free(str2);
}

/*
 * #FT_ERROR_MSG
 * 		The function writes an error message in red color.
 *
 * #PARAMETER
 * 		- char * msg -> The string to be printed
 *
 * #RETURN
 *		- 0 when the program finishes.
 */
int	ft_error_msg(char *msg)
{
	if (1)
	{
		write(0, "\033[0;31m", 7);
		write(0, msg, ft_strlen(msg));
	}
	return (0);
}

/*
 * #FT_F_SON
 * 		The function completes the command path (cmd_path_com) adding the command
 * 		to execute and the end of the string.
 * 		It duplicates the writing file descriptor in the STDOUT_FILENO so
 * 		in the output you have the same info than the fd.
 * 		It duplicates the info in the input fd (input_f) in the STDIN_FILENO so
 * 		in the input you have the information from the input file.
 * 		Then, it executes the command through the execve function.
 *
 * #PARAMETER
 * 		- int *fd -> the ipe FDs.
 * 		- char **argv -> the program input arguments.
 * 		- char **env -> the environment variables.
 * 		- struct s_paths t_path -> struct with command arguments & command path.
 *
 * #RETURN
 *		-
 */
void	ft_f_son(int *fd, char **argv, char **env, t_path p_data)
{
	char	*cmd_path_com;
	int		input_f;

	close(fd[READ_END]);
	if (p_data.cmd_path == NULL)
		return ;
	cmd_path_com = ft_strjoin(p_data.cmd_path, p_data.cmd_args[0]);
	input_f = open(argv[1], O_RDONLY);
	if (input_f == -1)
	{
		ft_error_msg("Error.\nNot possible to read from the input file\n");
		return ;
	}
	dup2(fd[WRITE_END], STDOUT_FILENO);
	dup2(input_f, STDIN_FILENO);
	close(fd[WRITE_END]);
	execve(cmd_path_com, p_data.cmd_args, env);
}

/*
 * #FT_FATHER
 * 		The function completes the command path (cmd_path_com) adding the command
 * 		to execute and the end of the string.
 * 		It duplicates the output file descriptor in the STDOUT_FILENO so
 * 		in the output file you'll have the same info than the fd.
 * 		It duplicates the info from the read file descriptor in the STDIN_FILENO so
 * 		in the input you have the information from the input file comming from
 * 		the son.
 * 		Then, it executes the command through the execve function.
 *
 * #PARAMETER
 * 		- int *fd -> the ipe FDs.
 * 		- char **argv -> the program input arguments.
 * 		- char **env -> the environment variables.
 * 		- struct s_paths t_path -> struct with command arguments & command path.
 *
 * #RETURN
 *		-
 */
void	ft_father(int *fd, char **argv, char **env, t_path p_data)
{
	char	*cmd_path_com;
	int		output_f;

	wait(NULL);
	close(fd[WRITE_END]);
	if (p_data.cmd_path == NULL)
		return ;
	cmd_path_com = ft_strjoin(p_data.cmd_path, p_data.cmd_args[0]);
	output_f = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH);
	if (output_f == -1)
	{
		ft_error_msg("Error.\nNot possible to create the output\n");
		return ;
	}
	dup2(output_f, STDOUT_FILENO);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	execve(cmd_path_com, p_data.cmd_args, env);
}
