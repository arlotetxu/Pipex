/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:03:32 by jflorido          #+#    #+#             */
/*   Updated: 2022/09/17 13:21:04 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_strdup ---> Allocate enought memory to copy a string 

  SYNOPSIS
  ***********
  #include <stdlib.h>
  char	*ft_strdup(const char *s1)

  DESCRIPTION
  ***********
  The strdup() function allocates enought memory to copy a string 
  It mimics the strdup function from the string library.

  PARAMETERS
  **********
  *s1 ---> String to be copied after memory reservation.

  RETURN VALUE
  ************
  - The function return a pointer to the created string.

*/

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_strlen(s1);
	i = 0;
	ptr = malloc(len * (sizeof(*s1)) + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
