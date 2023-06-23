/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:25:05 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 19:08:26 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_striteri ---> Apply a function to all characters of a given string 

  SYNOPSIS
  ***********
  #include <stdlib.h>
  ft_striteri(char *s, void (*f)(unsigned int, char*))

  DESCRIPTION
  ***********
  The ft_striteri() function apply a function (f) to all character of the
  string s.

  PARAMETERS
  **********
  *s ---> String to apply the f function.
  *f ---> A pointer to the function be applied.

  RETURN VALUE
  ************

*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
