/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:56:45 by mecauchy          #+#    #+#             */
/*   Updated: 2023/01/05 11:16:11 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elm;

	new_elm = malloc((sizeof(*new_elm)));
	if (!new_elm)
		return (NULL);
	new_elm->content = content;
	new_elm->next = NULL;
	return (new_elm);
}
