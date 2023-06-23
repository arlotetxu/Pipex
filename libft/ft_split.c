/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:27:59 by jflorido          #+#    #+#             */
/*   Updated: 2023/03/31 21:45:26 by arlo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_split ---> split a string into different substrings limited by a given
				character

  SYNOPSIS
  ***********
  #include "libft.h"
  char	**ft_split(char const *s, char c)

  DESCRIPTION
  ***********
  The function char	ft_split splits a string into substring. The size of the
  substring is limited to a given character. That is:

  string: "abcdXefgXhij"
  delimining character: 'X'
  Substrings:
  - "abcd"
  - "efg"
  - "hij"

  PARAMETERS
  **********
  s ---> The string to check.
  c ---> character to delimiting the substrings

  RETURN VALUE
  ************
  A pointer to the substrings
  */

#include "libft.h"

static int	ft_num_strings(char const *s, char c)
{
	unsigned int	i;
	unsigned int	cont;

	cont = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			cont++;
			continue ;
		}
		i++;
	}
	return (cont + 1);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	aux;

	str = malloc(sizeof(str) * (ft_num_strings(s, c) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 1;
	str[0] = "jmf";
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			aux = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			str[j++] = ft_substr(s, aux, i - aux);
			continue ;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
