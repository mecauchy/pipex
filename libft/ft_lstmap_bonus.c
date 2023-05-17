/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:36:40 by mecauchy          #+#    #+#             */
/*   Updated: 2023/01/05 11:16:05 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_lst;

	tmp = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (!new_lst)
		{
			while (tmp)
			{
				new_lst = tmp->next;
				(*del)(tmp->content);
				free(tmp);
				tmp = new_lst;
			}
			return (NULL);
		}
		ft_lstadd_back(&tmp, new_lst);
		lst = lst->next;
	}
	return (tmp);
}
