/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:51:18 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:22:57 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_memset ---> put a value (n) in a string 
  				(previously converted to unsigned char) len times. 

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

  ALTERNATIVE CODE
  ******************
  	while (len)
		*(unsigned char *)(b + --len) = (unsigned char)c;
	  return ((char *)b);
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
