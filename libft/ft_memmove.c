/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:57:35 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:21:48 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_memmove---> memory move

  SYNOPSIS
  ***********
  	#include <string.h>
	void	*ft_memmove(void *dst, const void *src, size_t len)

  DESCRIPTION
  ***********
  The function ft_memmove() mimics the behavior of the memmove() 
  function from string C library. Both functions move n bytes (len) 
  from memory area src to memory area dst when dst is greater than src.
  Otherwise, only dest len characters will be copied.

  PARAMETERS
  **********
	void *dst ---> Destination string;
	const void src ---> Source string;
	size_t len ---> Number of bytes to be copied

  RETURN VALUE
  ************
  - NULL if src is greater than dest.
  - dst modified.
  */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	return (dst);
}
