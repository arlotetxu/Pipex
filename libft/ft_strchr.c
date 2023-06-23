/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:07:45 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/12 16:36:02 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_strchr ---> locate a character (int) in a string
  len times. 

  SYNOPSIS
  ***********
  #include <string.h>
char	*strchr(const char *s, int c)

  DESCRIPTION
  ***********
  The strchr() function locates the first given character in a string. 
  It mimics the strchr function from the string library.

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

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ((char)c))
			return (&str[i]);
		i++;
	}
	if (((char)c) == '\0')
		return (&str[i]);
	return (0);
}
