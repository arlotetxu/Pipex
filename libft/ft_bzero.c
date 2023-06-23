/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:44:04 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/07 17:32:35 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_memset ---> put a value (n) in a string (previously converted to unsigned 
  				char)
  len times. 

  SYNOPSIS
  ***********
  #include <strings.h>
  void	*memset(void *b, int c, size_t len);

  DESCRIPTION
  ***********
  The memset() function fills the first n bytes of the memory area
  pointed to by s with the constant byte c.

  PARAMETERS
  **********
  *b ---> The string position (pointer).
  c ---> The value to add.
  len ---> number of times to add 'c'.

  RETURN VALUE
  ************
  - b. pointer modified.
  - 


  RETURN A CONDITION
  ******************
  When we return a condition, the computer will check if the condition is true or
  false. If it is true it will return 1(boolean true) and if it is false it will
  return 0(boolean false).

  ALTERNATIVE CODE
  ******************
  	while (len)
		*(unsigned char *)(b + --len) = (unsigned char)c;
	  return ((char *)b);
 
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, 0, n);
}
