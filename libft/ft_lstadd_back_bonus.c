/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:39:00 by mecauchy          #+#    #+#             */
/*   Updated: 2023/01/05 11:16:33 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elm;

	last_elm = 0;
	if (lst)
	{
		if (*lst)
		{
			last_elm = ft_lstlast(*lst);
			last_elm->next = new;
		}
		else
			*lst = new;
	}
}
