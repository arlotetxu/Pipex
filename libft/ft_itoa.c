/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:29:09 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/03 09:26:16 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_itoa ---> convert an integer value in a string

  SYNOPSIS
  ***********
  char	*ft_itoa(int n)

  DESCRIPTION
  ***********
  The function ft_itoa() converts an integer value in a string taking into
  account the sign. Carefull with the lower integer value... it is needed
  a special condition to convert it.

  PARAMETERS
  **********
  n ---> The integer to be converted.

  RETURN VALUE
  ************
  - NULL if the memory allocation is null.
  - String with the digits from the integer n.
*/

#include "libft.h"

static int	ft_num_dim(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*create_str(int n)
{
	char	*str;
	int		digits;
	int		is_neg;

	is_neg = 0;
	digits = ft_num_dim(n);
	str = malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		is_neg = 1;
	}
	if (n == 0)
		str[0] = '0';
	str[digits] = '\0';
	while (digits != is_neg)
	{
		str[digits - 1] = (n % 10) + '0';
		n = n / 10;
		digits--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = malloc(sizeof(char) * 12);
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	else
		str = create_str(n);
	return (str);
}
