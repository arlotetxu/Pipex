/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:20:25 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/07 17:21:44 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_isdigit ---> is an numeric character (values between 48 & 57 in ASCII CODE)

  SYNOPSIS
  ***********
  #include <ctype.h>
  int	isalpha(int c);
  #include "libft.h"
  int	ft_isalpha(int c);

  DESCRIPTION
  ***********
  The function ft_isdigit() mimics the behavior of the isdigit() function from
  ctype C library. Both functions check if c is an alphabetic character.

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
  return(c >= '0' && c <= '9');
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
