/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:25:08 by mecauchy          #+#    #+#             */
/*   Updated: 2022/12/26 16:07:15 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	a;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)b;
	a = (unsigned char)c;
	while (n)
	{
		ptr[i] = a;
		i++;
		n--;
	}
	return (ptr);
}
