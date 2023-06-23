/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:06:18 by jflorido          #+#    #+#             */
/*   Updated: 2023/04/01 11:48:48 by arlo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_atoi ---> get the number portion of a string

  SYNOPSIS
  ***********
  #include <stdlib.h>
  int	ft_atoi(const char *str)

  DESCRIPTION
  ***********
  The function ft_atoi() mimics the behavior of the atoi() function from
  string C library. Both functions converts the initial portion of the 
  string pointed to by str to int representation.
  * The string can strart with spaces or other Ascii 
  	control caracters (9 --> 13)
  ** Then, the string can continue with a sign. If there are more than a sign
	the return should be 0
  *** Finally,the string should continue with digits.
  If the string does not follow this logic, the functions should return 0.

  PARAMETERS
  **********
  *str ---> The string to be checked.

  RETURN VALUE
  ************
  - Number contained in the string included it sign.
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

static int	ft_checksign(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (!(str[i] >= 48 && str[i] <= 57))
	{
		if (str[i] == 43 || str[i] == 45)
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;
	int	c_sign;

	i = 0;
	sign = 1;
	c_sign = ft_checksign(str);
	while ((str[i] != '\0' && str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i] != '\0' && (str[i] == 43 || str[i] == 45))
	{
		if (c_sign == 0)
			return (0);
		if (str[i] == 45)
			sign = -1;
		i++;
	}	
	n = 0;
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
