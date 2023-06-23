/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:14:43 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:19:36 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_memcmp ---> Compare 2 strings

  SYNOPSIS
  ***********
	#include <string.h>
	int	ft_memcmp(const void *s1, const void *s2, size_t n)

  DESCRIPTION
  ***********
  The function ft_memcmp() mimics the behavior of the memcmp()
  function from string C library. Both functions compares byte string s1 
  against byte string s2. Both strings are assumed to be n bytes long.

  PARAMETERS
  **********
	const void *s1 ---> string1;
	const void *s2 ---> string2;
	size_t n ---> Number of bytes to check in the strings.

  RETURN VALUE
  ************
  - 0 if the strings are identical.
  - Diference between the first two different bytes (Ascii code).
  */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = ((char *)s1);
	str2 = ((char *)s2);
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (((unsigned char) str1[i]) - ((unsigned char)str2[i]));
		i++;
	}
	return (0);
}
