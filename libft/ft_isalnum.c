/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:52:38 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:13:18 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_isalnum ---> is an numeric character (values between 48 & 57 in ASCII CODE)

  SYNOPSIS
  ***********
  #include <ctype.h>
  #include "libft.h"
  int	ft_isalnum(int c);

  DESCRIPTION
  ***********
  The function ft_isalnum() mimics the behavior of the isalnum() function 
  from ctype C library. Both functions check if c is an alphabetic or 
  numeric character.

  PARAMETERS
  **********
  c ---> The character to be checked.

  RETURN VALUE
  ************
  - One value if c is a digit.
  - Zero value if not.


  RETURN A CONDITION
  ******************
  When we return a condition, the computer will check if the condition is true or
  false. If it is true it will return 1(boolean true) and if it is false it will
  return 0(boolean false).

  ALTERNATIVE CODE
  ******************
  return(ft_isdigit(c) || ft_isalpha(c));
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) == 1 || ft_isalpha(c) == 1)
		return (1);
	else
		return (0);
}
