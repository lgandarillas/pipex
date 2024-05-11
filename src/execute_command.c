/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:33:57 by lgandari          #+#    #+#             */
/*   Updated: 2024/04/14 19:16:00 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	print_error(char *msg, int exit_code)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(exit_code);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	get_path_index(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		else
			i++;
	}
	return (print_error("Path not found.\n", 127));
}

char	*get_path(char *cmd, char **env)
{
	char	**directories;
	char	*path;
	char	*directory;
	int		index;
	int		i;

	if (cmd == NULL)
		return (NULL);
	index = get_path_index(env);
	directories = ft_split(env[index] + 5, ':');
	i = 0;
	while (directories[i])
	{
		directory = ft_strjoin("/", cmd);
		path = ft_strjoin(directories[i++], directory);
		free(directory);
		if (access(path, X_OK) == 0)
		{
			free_split(directories);
			return (path);
		}
		free(path);
	}
	free_split(directories);
	return (0);
}

int	execute_command(char *cmd, char **env)
{
	char	**cmd_parts;
	char	*path;

	if (cmd)
		cmd_parts = ft_split(cmd, ' ');
	else
		return (print_error("Command not found.\n", 127));
	path = get_path(cmd_parts[0], env);
	if (!path)
	{
		free_split(cmd_parts);
		return (print_error("Command not found.\n", 127));
	}
	if (execve(path, cmd_parts, env) == -1)
		free_split(cmd_parts);
	return (print_error("Exec failed.\n", 127));
}
