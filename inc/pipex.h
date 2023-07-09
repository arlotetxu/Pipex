/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:06:23 by jflorido          #+#    #+#             */
/*   Updated: 2023/06/29 19:00:53 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../libft/libft.h"
// Struct to store the path & comands
typedef struct s_paths {
	char	*cmd_path;
	char	**cmd_args;
}				t_path;
//MAIN FUNCTIONS
int		main(int argc, char **argv, char **env);
void	ft_launch_f_son(int *fd, char **argv, char **env);
void	ft_launch_father(int *fd, char **argv, char **env);
//PATH FUNCTIONS
char	*ft_get_path(char **env);
char	**ft_get_path_str(char *env);
char	**ft_get_cmd_args(char *argv);
char	*ft_where_is(char *cmd, char **env);
//PIPEX FUNCTIONS
void	ft_free(char **str);
int		ft_error_msg(char *msg);
void	ft_f_son(int *fd, char **argv, char **env, t_path p_data);
void	ft_s_son(int *fd, char **argv, char **env, t_path p_data);
void	ft_father(int *fd, char **argv, char **env, t_path p_data);
// Defines for fd
# define READ_END 0
# define WRITE_END 1

#endif
