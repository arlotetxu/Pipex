/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:57:05 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/10 17:00:16 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_tolower ---> covert to lower an upper character

  SYNOPSIS
  ***********
  #include <ctype.h>
  int	tolower(int c);

  DESCRIPTION
  ***********
  The function ft_tolower() mimics the behavior of the tolower() function from
  CTYPE library. Both functions converts a character in uppercase in lowercase.
  

  PARAMETERS
  **********
  c ---> integer value of the character.

  RETURN VALUE
  ************
  - interger value of the lower character.
  If the character is not an upper character, the function return the original 
  int value
  
  
  RETURN A CONDITION
  ******************
  When we return a condition, the computer will check if the condition is true or
  false. If it is true it will return 1(boolean true) and if it is false it will
  return 0(boolean false).

  ALTERNATIVE CODE
  ******************
 
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
