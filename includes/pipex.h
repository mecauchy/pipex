/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melissacauchy <melissacauchy@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:27:42 by melissacauc       #+#    #+#             */
/*   Updated: 2023/05/08 14:32:12 by melissacauc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "../libft/libft.h"
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <signal.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

// PROTOTYPE //

void    pipex(int ac, char **av, char **env);
void    first_cmd_exec(int *fd, char **av,char **env);
void    second_cmd_exec(int *fd, char **av, char **env);
void    executer(char *cmd, char **env);
char    **ft_get_paths(char **env);
void    ft_error(char *msg, int exit_code);
void	free_cmds(char *cmd, char **cmds);
pid_t   fork(void);


// STRUCTURE //

typedef struct s_data
{
    char    **env;
    char    **av;
    int     ac;
    int     fd_in;
    int     fd_out;
    int     child;
    char    *cmd_path;
}   t_data;

// SINGLETON //

t_list  *_cmd(void);

#endif