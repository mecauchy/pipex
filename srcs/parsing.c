/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melissacauchy <melissacauchy@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:54:38 by melissacauc       #+#    #+#             */
/*   Updated: 2023/05/08 13:26:40 by melissacauc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    parsing(char *cmd)
{
    char    **cmd_split;
    
    cmd_split = ft_split(cmd, ' ');
    execve(cmd_split[0], cmd_split, NULL); // path arg env //
}



char    **ft_get_paths(char **env)
{
	int     i;
	char    **paths;

	i = 0;
	paths = NULL;
	// compare chaque caracteres apres path=
	while (!ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	// chemin extrai avec split de la variable path et decoupé : //
	return (paths);
}


// join char *cmd et char *"/" = cmd/cmd....
static char **usable_path(char **cmds)
{
    int i;
    int tmp;

    i = 0;
    tmp = NULL;
    while (cmds[i])
    {
        tmp = path[i];
        cmds[i] = ft_strjoin(cmds, "/");
        free_function(tmp, NULL);
        i++;
    }
}

// cherche la cmd dans les paths
static char cmd_path(char *cmd, char **paths)
{
    int i;
    char *cmd_path;

    i = 0;
    while (paths[i])
    {
        cmd_path = ft_strjoin(paths[i], cmd);
        if (!cmd_path)
        {
            free_function(NULL, paths);
            exit_error(msg(""));
        }
        if (access(cmd_path, F_OK | X_OK) == 0)
            return (cmd_path);
        free(cmd_path, NULL);
        i++;
    }
    return (NULL);
}

char	*get_cmd(char *cmd, t_data *data)
{
	char	**env_paths;
	char	*cmd_path = NULL;

	// Vérifie si le fichier existe et est exécutable dans le répertoire courant
	if (access(cmd, F_OK | X_OK) == 0)
    {
		cmd_path = ft_strdup(cmd);
		if (!cmd_path)
			exit_error(msg("unexpected error", "", "", 1), NULL);
		return (cmd_path);
	}
	// Récupère les chemins des répertoires définis dans la variable d'environnement PATH
	env_paths = get_env_paths(data->envp);
	if (!env_paths)
		return (NULL);
	// Cherche le chemin d'accès complet du fichier binaire dans les répertoires de la variable PATH
	cmd_path = get_cmd_path(cmd, env_paths);
	if (!cmd_path)
		msg("command not found", ": ", data->av[data->child + 2], 1);
        //nom de la commande que l'utilisateur a entrée en argument.
	free_strs(NULL, env_paths);
	return (cmd_path);
}


pid_t   fork(void)
{
    pid_t   pid;
    
    pid = fork();
    if (pid == -1)
        ft_error("error : fork");
    return (pid);
}
