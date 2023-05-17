/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melissacauchy <melissacauchy@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:28:02 by melissacauc       #+#    #+#             */
/*   Updated: 2023/05/08 16:47:56 by melissacauc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void  init(void)
{
    t_data  *data;

    data = _cmd();
    data->ac = -1;
    data->fd_in = -1;
    data->fd_out = -1;
    data->child = -1;
    // -1 pour eviter les segfault car sinon 0 valide//
}

void    init_struct(int ac, char **av, char **env)
{
    t_data  *data;

    data = _cmd();
    data->ac = ac;
    data->av = av;
    data->env = env;
    init();
}
