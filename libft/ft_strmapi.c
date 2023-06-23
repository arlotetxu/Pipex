/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:55:15 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:58:17 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_strmapi ---> Apply a function to a given string

  SYNOPSIS
  ***********
  *ft_strmapi(char const *s, char (*f)(unsigned int, char))

  DESCRIPTION
  ***********
  The function ft_strmapi() apply the function (f), giving as parameter
  of the function the index of each character in the string s.

  PARAMETERS
  **********
  *s ---> The string.
  *f ---> Function to apply. Param: index and character 

  RETURN VALUE
  ************
  - A pointer to the new modified string.
  - 


  RETURN A CONDITION
  ******************
  When we return a condition, the computer will check if the condition is true or
  false. If it is true it will return 1(boolean true) and if it is false it will
  return 0(boolean false).

  ALTERNATIVE CODE
  ******************
 
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
