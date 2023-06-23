/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:27:36 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:16:28 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_isprint ---> is a printable character (ASCII from 32 to 126)

  SYNOPSIS
  ***********
  #include <ctype.h>
  int	isprint(int c);

  DESCRIPTION
  ***********
  The function ft_isprint() mimics the behavior of the isprint() 
  function from ctype C library. Both functions check if c is a printable 
  character within the ASCII code (values between 32 and 126).

  PARAMETERS
  **********
  c ---> The character to be checked.

  RETURN VALUE
  ************
  - One value if c is an printable ascii character.
  - Zero value if not.


  RETURN A CONDITION
  ******************
  When we return a condition, the computer will check if the condition 
  is true or false. If it is true it will return 1(boolean true) and 
  if it is false it will return 0(boolean false).

  ALTERNATIVE CODE
  ******************
  return(c >= 32 && c <= 126));
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
