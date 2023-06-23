/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:42:40 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/07 17:32:46 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_isascii ---> is an ascii character

  SYNOPSIS
  ***********
  #include <ctype.h>
  int	isascii(int c);

  DESCRIPTION
  ***********
  The function ft_isascii() mimics the behavior of the isascii() function from
  ctype C library. Both functions check if c is within the ASCII code 
  (values between 0 and 127).

  PARAMETERS
  **********
  c ---> The character to be checked.

  RETURN VALUE
  ************
  - One value if c is an ascii character.
  - Zero value if not.


  RETURN A CONDITION
  ******************
  When we return a condition, the computer will check if the condition is true or
  false. If it is true it will return 1(boolean true) and if it is false it will
  return 0(boolean false).

  ALTERNATIVE CODE
  ******************
  return(c >= 0 && c <= 127));
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
