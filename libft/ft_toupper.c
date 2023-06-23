/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:26:22 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/10 16:54:37 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_toupper ---> covert to upper a lower character

  SYNOPSIS
  ***********
  #include <ctype.h>
  int	toupper(int c);

  DESCRIPTION
  ***********
  The function ft_to upper() mimics the behavior of the toupper() function from
  CTYPE library. Both functions converts a character in lowercase in uppercase.
  

  PARAMETERS
  **********
  c ---> integer value of the character.

  RETURN VALUE
  ************
  - interger value of the upper character.
  If the character is not a lower character, the function return the original 
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

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
