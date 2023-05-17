/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:39:37 by mecauchy          #+#    #+#             */
/*   Updated: 2022/12/22 17:01:03 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_len(long n)
{
	long	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long n)
{
	char	*str;
	int		count;

	count = ft_len(n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	str[count] = '\0';
	while (n > 0)
	{
		count--;
		str[count] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
