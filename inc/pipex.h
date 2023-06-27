/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:06:23 by jflorido          #+#    #+#             */
/*   Updated: 2023/06/23 13:06:23 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PIPEX_H
# define PIPEX_PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
#include "../libft/libft.h"

//PATH FUNCTIONS
char	*ft_get_path(char **env);
char	**ft_get_path_str(char *env);
char	**ft_get_cmd_args(char *argv);
char	*ft_where_is(char *cmd, char **env);

//PIPEX FUNCTIONS
void	ft_free(char **str);
int		ft_error_msg(char *message);
void	ft_f_son(int *fd, char **argv, char **env, char *cmd_path, char **cmd_args);
void	ft_s_son(int *fd, char **argv, char **env, char *cmd_path, char **cmd_args);


// Defines for fd
# define READ_END 0
# define WRITE_END 1
#endif //PIPEX_PIPEX_H
