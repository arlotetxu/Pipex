/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:07:56 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/12 20:24:29 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_strncmp ---> compare n character of 2 strings

  SYNOPSIS
  ***********
  #include <string.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n)

  DESCRIPTION
  ***********
  The strncmp() function compares n characters of 2 string and return the
  difference between the ascii value of the different characters. It mimics
  the strncmp function of the standard C library contained in the string.h
  library.

  PARAMETERS
  **********
  *s1 ---> String 1.
  *s2 ---> String 2.
  n ---> Number of characters to be compared.

  RETURN VALUE
  ************
  - The function returns a the difference of the distinct character
  ascii values.


  RETURN A CONDITION
  ******************
  When we return a condition, the computer will check if the condition is true or
  false. If it is true it will return 1(boolean true) and if it is false it will
  return 0(boolean false).
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n > 0)
	{
		if (*s1 != *s2)
			return (((unsigned char) *s1) - ((unsigned char) *s2));
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (((unsigned char) *s1) - ((unsigned char) *s2));
}
