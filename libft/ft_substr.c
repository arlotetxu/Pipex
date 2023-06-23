/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:23:38 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/22 14:56:32 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_substr ---> Creates a substring of 'len' bytes starting 
  				 in the 'start'.

  SYNOPSIS
  ***********
  char	*ft_substr(char const *s, unsigned int start, size_t len)

  DESCRIPTION
  ***********
  The ft_substr creates a substring starting from the start value
  parameter and with the total size of 'len' parameter.
  
  PARAMETERS
  **********
  *s ---> String to modify.
  start ---> The initial byte to start the substring
  len ---> maximum size of the resultant string

  RETURN VALUE
  ************
  - The function returns a pointer to the new string (malloc).
  
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	new_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup (""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	substr = (char *)malloc(sizeof(char) *(len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}