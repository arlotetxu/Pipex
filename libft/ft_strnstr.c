/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:11:24 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/14 19:01:43 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_strnstr ---> locate a string within a string in a len bytes
  len times. 

  SYNOPSIS
  ***********
  #include <string.h>
  char	*ft_strnstr(const char *hsk, const char *ndl, size_t len)

  DESCRIPTION
  ***********
  The strnstr() function locates a given string in a string where no more
  than len characters are searched.
  It mimics the strnstr function from the string library.

  PARAMETERS
  **********
  *hsk ---> String where to search.
  *ndl ---> String to be search.
  len ---> Number of character from the *hsk to search.

  RETURN VALUE
  ************
  - If ndl is an empty string, hsk is returned; if ndl is not in hsk, 
  NULL is returned; otherwise a pointer to the first character of the 
  first occurrence of ndl is returned.


  RETURN A CONDITION
  ******************
  When we return a condition, the computer will check if the condition is true or
  false. If it is true it will return 1(boolean true) and if it is false it will
  return 0(boolean false).
*/

#include "libft.h"

char	*ft_strnstr(const char *hsk, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ndl[i] == '\0')
		return (((char *)hsk + i));
	while (hsk[i] != '\0' && i < len)
	{
		if (hsk[i] == ndl[j])
		{
			while (hsk[i + j] == ndl[j] && ((i + j) < len))
			{
				if (ndl[j + 1] == '\0')
					return (((char *)hsk + i));
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
