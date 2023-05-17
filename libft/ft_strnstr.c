/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:44:39 by mecauchy          #+#    #+#             */
/*   Updated: 2022/12/16 15:06:52 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	ptr = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			ptr = (char *)haystack + i;
			j = 0;
			while (haystack[i + j] && haystack[i + j] == needle[j]
				&& i + j < len)
			{
				if (needle[j + 1] == '\0')
					return (ptr);
				j++;
			}
		}	
		i++;
	}
	return (NULL);
}
