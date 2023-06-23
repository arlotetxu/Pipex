/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:30:36 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:40:30 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_putstr_fd ---> send a string to a filedescriptor

  SYNOPSIS
  ***********
  #include "libft.h"
  #include <unistd.h>
  void ft_putstr_fd(char *s, int fd);

  DESCRIPTION
  ***********
  The function ft_putstr_fd send a string to the specified filedescriptor

  PARAMETERS
  **********
  s ---> The string to be sent.
  fd ---> filedescriptor

  RETURN VALUE
  ************
  Nothing
*/

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
