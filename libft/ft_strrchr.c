/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:34:42 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/12 17:14:42 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_strrchr ---> locate the last given character (int) in a string
  len times. 

  SYNOPSIS
  ***********
  #include <string.h>
char	*strrchr(const char *s, int c)

  DESCRIPTION
  ***********
  The strchr() function locates the last given character in a string. 
  It mimics the strrchr function from the string library.

  PARAMETERS
  **********
  *s ---> String.
  c ---> Character to find.

  RETURN VALUE
  ************
  - The function return a pointer to the found character.


  RETURN A CONDITION
  ******************
  When we return a condition, the computer will check if the condition is true or
  false. If it is true it will return 1(boolean true) and if it is false it will
  return 0(boolean false).
*/

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	char	*str;

	str = (char *)s;
	l = ft_strlen(s);
	while (l >= 0)
	{
		if (str[l] == ((char)c))
			return (&str[l]);
		l--;
	}
	return (0);
}
