/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melissacauchy <melissacauchy@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:59:12 by melissacauc       #+#    #+#             */
/*   Updated: 2023/05/07 12:57:58 by melissacauc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    ft_error(char *msg, int exit_code)
{
	ft_putstr_fd(msg, 2);
	exit(exit_code);
}

void	free_cmds(char *cmd, char **cmds)
{
	int	i;

	if (cmd != NULL)
	{
		free(cmd);
		cmd = NULL;
	}
	if (cmds != NULL)
	{
		i = 0;
		while (cmds[i])
		{
			free(cmds[i]);
			cmds[i] = NULL;
			i++;
		}
		free(cmds);
		cmds = NULL;
	}
}