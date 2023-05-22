/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melissacauchy <melissacauchy@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:38:37 by melissacauc       #+#    #+#             */
/*   Updated: 2023/05/11 13:49:25 by melissacauc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    executer(char *cmd, char **env)
{
    int     i;
    int     status;
    pid_t   pid;
    char    *cmd_path;
    char    **path;
    
    i = 0;
    path = ft_get_paths(env);
    if (path == NULL)
        ft_error("error : path not found", 1);
    while (path[i])
    {
        cmd_path = ft_strjoin(path[i], cmd);
        i++;
    }
    // cherche la cmd //
    cmd_path = ft_strjoin(path[1], cmd);
    // chemin d'acces complet cmd //
    execve(cmd_path, cmd, env);
    // execve permet d'executer la cmd
    // si execve echoue, on affiche un message d'erreur
    if (pid == 0)
    {
        perror("execve");
        exit(EXIT_FAILURE);
    }
    if (waitpid(pid, &status, 0) == -1) 
    { 
        // Attente de la fin du processus fils
        perror("waitpid");
        exit(EXIT_FAILURE);
    }
}

/*void executer(char *str, char **env)
{
    pid_t pid;
    int i;
    char **cmd_path;
    char **path;
    int status;

    i = 0;
    path = ft_get_paths(env);
    if (path == NULL)
        perror("path");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) 
    { // Processus fils
        execve(str, NULL, env); // Exécution de la commande
        perror("execve"); // Affichage d'un message d'erreur en cas d'échec
        exit(EXIT_FAILURE);
    }
    else { // Processus parent
        if (waitpid(pid, &status, 0) == -1) 
        { // Attente de la fin du processus fils
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
    }
}*/

// redirection vers sortie fd[1] : sortie standart
void    first_cmd_exec(int *fd, char **av,char **env)
{
    int fd_out;
    // ajt cmd parsing split ' '//
    
    fd_out = open(av[1], 0_RDONLY);
    if (fd_out < 0)
        ft_perror("error : open file");
    dup2(fd[1], STDOUT_FILENO); // ecrit dans fd[1]
    dup2(fd_out, STDIN_FILENO); // devient cmd1 sortie stdout
    // close les fds non utilisés
    // p child : écriture
    executer(av[2], env);
    // av[2] : premiere cmd a executer
    close(fd[0]);
    close(fd_out);
    close(fd[1]);
}

// 2nde cmd redirection vers entree fd[0] : entree standart
void    second_cmd_exec(int *fd, char **av, char **env)
{
    int fd_in;

    fd_in = open(av[4], 0_RDONLY);
    if (fd_in < 0)
        ft_perror("error : open file");
    dup2(fd[0], STDIN_FILENO);
    dup2(fd_in, STDOUT_FILENO);
    close(fd[1]);
    close(fd_in);
    close(fd[0]);
    executer(av[3], env);
}

void    pipex(int ac, char **av, char **env)
{
    int     fd[2];
    int     pid1;
    int     pid2;
    int     status;

    if (ac < 5)
        ft_error("error : arguments");
    if (ac == 5)
    {
         // parsing(av);
        pid1 = fork();
        if (pid1 == -1)
            ft_perror("[PID1] ERROR");
        if (pid1 == 0)
            //child process
            first_cmd_exec(fd, av, env);
        waitpid(pid1, NULL, 0);
        pid2 = fork();
        if (pid2 == -1)
            ft_perror("[PID2] ERROR");
        else if (pid2 == 0)
            //child2 process
            second_cmd_exec(fd, av, env);
        waitpid(pid2, NULL, 0);
        /*else
        {
            waitpid(pid2, &status, 0);
        }
        */
        close(fd[0]);
        close(fd[1]);
    }
}

int main(int ac, char **av, char **env)
{
    pipex(ac, av, env);
    return (0);
}