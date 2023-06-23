/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:28:23 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 09:29:41 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
  NAME
  ****
  ft_strtrim ---> delete characters from the beginning and end of a string

  SYNOPSIS
  ***********
  char	*ft_strtrim(char const *s1, char const *set)

  DESCRIPTION
  ***********
  The strtrim removes the character from the string "set" in the string "s1",
  from the beginning and the end while a character not included in the 
  set string is found.
  
  PARAMETERS
  **********
  *s1 ---> String to modify.
  *set ---> String with characters to check.

  RETURN VALUE
  ************
  - The function returns a pointer to the new string (malloc).
  
*/

#include "libft.h"

static int	pos_left(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0' && s1[i] != s2[j])
			j++;
		while (s2[j] == '\0')
			return (i);
		i++;
	}
	return (0);
}

static int	pos_right(char const *s1, char const *s2)
{
	size_t	j;
	size_t	len;

	if (ft_strlen(s1) == 0)
		len = 1;
	else
		len = ft_strlen(s1);
	while (len >= 0)
	{
		j = 0;
		while (s2[j] != '\0' && s1[len - 1] != s2[j])
			j++;
		while (s2[j] == '\0')
			return (len);
		len--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;
	size_t	r;
	size_t	i;
	char	*str;

	l = pos_left(s1, set);
	r = pos_right(s1, set);
	str = malloc (sizeof(char) * (r - l + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (l < r)
	{
		str[i] = s1[l];
		i++;
		l++;
	}
	str[i] = '\0';
	return (str);
}
