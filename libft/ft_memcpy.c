/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:58:27 by mecauchy          #+#    #+#             */
/*   Updated: 2022/12/26 16:30:00 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*v_dest;
	unsigned char	*v_src;
	int				i;

	v_dest = (unsigned char *)dest;
	v_src = (unsigned char *)src;
	i = 0;
	while (n)
	{
		v_dest[i] = v_src[i];
		i++;
		n--;
	}
	return (dest);
}
