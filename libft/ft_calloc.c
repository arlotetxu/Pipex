/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:53:29 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/17 11:50:59 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_calloc ---> Allocate contiguous memory

  SYNOPSIS
  ***********
  #include <stdlib.h>
  #include "libft.h"
  void	*ft_calloc(size_t count, size_t size)

  DESCRIPTION
  ***********
  The function ft_calloc() mimics the behavior of the calloc() function. 
  Both functions allocates contiguous memory with the defined 
  space (parameters). 

  PARAMETERS
  **********
  size_t count ---> Number of blocks to be reserved.
  size_t size --> size of each block in bytes.

  Ex. 8 blocks x sizeof(int) = 32 bytes

  RETURN VALUE
  ************
  - A pointer to the allocated memory.
*/

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_memset(ptr, 0, count * size);
	return (ptr);
}
