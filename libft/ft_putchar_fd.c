/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:23:50 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:32:26 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_putchar_fd ---> send a character to a filedescriptor

  SYNOPSIS
  ***********
  #include "libft.h"
  #include <unistd.h>
  void	ft_putchar_fd(char c, int fd)

  DESCRIPTION
  ***********
  The function ft_putchar_fd send a character to the specified filedescriptor

  PARAMETERS
  **********
  c ---> The character to be sent.
  fd ---> filedescriptor

  RETURN VALUE
  ************
  Nothing
*/

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
