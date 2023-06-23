/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:04:47 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:39:13 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_putendl_fd ---> send a string to a filedescriptor with a new line

  SYNOPSIS
  ***********
  #include "libft.h"
  #include <unistd.h>
  void ft_putendl_fd(char *s, int fd);

  DESCRIPTION
  ***********
  The function ft_putendl_fd send a string to the specified filedescriptor
  adding a new line at the end of the string.

  PARAMETERS
  **********
  *s ---> The string to be sent.
  fd ---> filedescriptor

  RETURN VALUE
  ************
  Nothing
*/

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
