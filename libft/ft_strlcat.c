/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:43:06 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:51:40 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_strlcat ---> concatenating strings

  SYNOPSIS
  ***********
  #include <string.h>
  size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)

  DESCRIPTION
  ***********
  The strlcat() function concatenates n characters from a source string to a
  destination string, depending on the parameters. The number of the characters
  to be copies depends on the final dst destination.

  PARAMETERS
  **********
  *dst ---> Destination string.
  *src ---> Source string.
  dstsize ---> length of the final dst string.

  RETURN VALUE
  ************
  - the strlcpy() and strlcat() functions return the total length of 
  the string they tried to create.  For strlcat() that means the initial 
  length of dst plus the length of src.


  RETURN A CONDITION
  ******************
  When we return a condition, the computer will check if the condition is true or
  false. If it is true it will return 1(boolean true) and if it is false it will
  return 0(boolean false).
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (src[j] != '\0' && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
