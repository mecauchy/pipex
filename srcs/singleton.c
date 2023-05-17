/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melissacauchy <melissacauchy@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:59:57 by melissacauc       #+#    #+#             */
/*   Updated: 2023/05/08 16:54:46 by melissacauc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_list	*_cmd(void)
{
	static t_list	cmd;
	static int		i = 0;
	
	if (i == 0)
	{
		ft_bzero(&cmd, sizeof(t_list));
		i++;
	}
	return (&cmd);
}

t_list  *_cmd(void)