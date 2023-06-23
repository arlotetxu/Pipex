/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:10:28 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/10 11:40:34 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_strlcpy ---> copies up to dstsize - 1 characters from the string src to 
  dst, NUL-terminating the result if dstsize is not 0
  len times. 

  SYNOPSIS
  ***********
  #include <string.h>
 size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)

  DESCRIPTION
  ***********
  The strlcpy() function copies n characters from a source string to a
  destination string, returning the length of the source string.

  PARAMETERS
  **********
  *dst ---> Destination string.
  *src ---> Source string.
  dstsize ---> number of characters to be copied.

  RETURN VALUE
  ************
  - the strlcpy() and strlcat() functions return the total length of 
  the string they tried to qcreate.  For strlcpy() that means the length of src.


  RETURN A CONDITION
  ******************
  When we return a condition, the computer will check if the condition is true or
  false. If it is true it will return 1(boolean true) and if it is false it will
  return 0(boolean false).
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	t;

	t = ft_strlen(src);
	if (!src || !dst)
		return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (t);
}
