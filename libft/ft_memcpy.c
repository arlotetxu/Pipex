/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 06:04:49 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:20:06 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_memcpy ---> memory copy

  SYNOPSIS
  ***********
  	#include <ctype.h>
  	#include <string.h>
	void	*ft_memcpy(void *dst, const void src, size_t n)

  DESCRIPTION
  ***********
  The function ft_memcpy() mimics the behavior of the memcpy() 
  function from string C library. Both functions copy n bytes 
  from memory area src to memory area dst.

  PARAMETERS
  **********
	void *dst ---> Destination string;
	const void src ---> Source string;
	size_t n ---> Number of bytes to be copied

  RETURN VALUE
  ************
  - NULL if one of the strings is empty.
  - dst modified.
  */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}
