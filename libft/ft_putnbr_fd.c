/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:24:43 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 19:08:13 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_putnbr_fd ---> send a number to a filedescriptor

  SYNOPSIS
  ***********
  #include "libft.h"
  #include <unistd.h>
  void ft_putnbr_fd(int n, int fd);

  DESCRIPTION
  ***********
  The function ft_putnbr_fd send a number to the specified filedescriptor

  PARAMETERS
  **********
  n ---> The number to be sent.
  fd ---> filedescriptor

  RETURN VALUE
  ************
  Nothing
*/

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*s;
	int		i;

	s = ft_itoa(n);
	i = 0;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	free (s);
}
