/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 07:55:21 by arlo              #+#    #+#             */
/*   Updated: 2022/10/03 18:15:06 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_isalpha ---> check if a value is alphanumeric (from 'A' to 'Z' and 
  				  from 'a' to 'z').

  SYNOPSIS
  ***********
  #include <ctype.h>
  #include "libft.h"
  int	ft_isalpha(int c);

  DESCRIPTION
  ***********
  The function ft_isalpha() mimics the behavior of the isalpha() function 
  from ctype C library. Both functions check if c is an alphabetic character.

  PARAMETERS
  **********
  c ---> The character to be checked.

  RETURN VALUE
  ************
  - One value if c is an alphabetic character.
  - Zero value if not.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
