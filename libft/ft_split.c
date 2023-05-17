/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:11:04 by mecauchy          #+#    #+#             */
/*   Updated: 2022/12/22 17:53:05 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char *str, char charset)
{
	if (*str == charset)
		return (1);
	return (0);
}

static int	ft_ltrcnt(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(ft_is_sep(str + i, charset)))
		i++;
	return (i);
}

static int	ft_wrdcnt(char *str, char charset)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		if (*str && ft_is_sep(str, charset))
			str++;
		i = ft_ltrcnt(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

static char	*ft_wdcpy(char *str, int size)
{
	char	*dest;

	dest = malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	dest[size] = '\0';
	while (size--)
		dest[size] = str[size];
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		size;
	int		i;
	int		j;

	i = 0;
	size = ft_wrdcnt((char *)s, c);
	str = malloc(sizeof(char *) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		while (*s && ft_is_sep((char *)s, c))
			s++;
		j = ft_ltrcnt((char *)s, c);
		str[i] = ft_wdcpy((char *)s, j);
		if (str[i] == NULL)
			return (NULL);
		s += j;
		i++;
	}
	str[size] = 0;
	return (str);
}
