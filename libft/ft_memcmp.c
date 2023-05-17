/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:25:35 by mecauchy          #+#    #+#             */
/*   Updated: 2022/12/26 16:39:29 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*v_s1;
	unsigned char	*v_s2;
	unsigned int	i;

	v_s1 = (unsigned char *)s1;
	v_s2 = (unsigned char *)s2;
	i = 0;
	if (!s1 || !s2 || n == 0)
		return (0);
	while (v_s1[i] == v_s2[i] && n > 1)
	{
		i++;
		n--;
	}
	return ((int)(v_s1[i] - v_s2[i]));
}
