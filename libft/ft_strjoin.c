/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:02:07 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 18:51:16 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_strjoin ---> Concatenate 2 strings allocating memory 

  SYNOPSIS
  ***********
  char	*ft_strjoin(char const *s1, char const *s2)

  DESCRIPTION
  ***********
  The ft_strjoin() function concatenates 2 different string allocating
  enought memory in the system. If there are not strings or memory
  allocation fails, the function return null. Otherwise, the function
  return a pointer to the final string.

  PARAMETERS
  **********
  *s1 ---> First String.
  *s2 ---> Second String to concatenate.

  RETURN VALUE
  ************
  - Null when there are not strings or memory allocation fails.
  - The function return a pointer to the final string.

*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n_str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	n_str = malloc(sizeof(char) * (len + 1));
	if (n_str == NULL)
		return (NULL);
	ft_strlcpy(n_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(n_str, s2, len + 1);
	return (n_str);
}
