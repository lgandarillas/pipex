/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:39:12 by lgandari          #+#    #+#             */
/*   Updated: 2024/04/20 17:29:12 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	first_son(int *fd, char **argv, char **env)
{
	int		fd1;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		fd1 = open(argv[1], O_RDONLY, 0644);
		if (fd1 < 0 || access(argv[1], R_OK) < 0)
			print_error("Failed to open or access infile.\n", 1);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		dup2(fd1, STDIN_FILENO);
		close(fd1);
		execute_command(argv[2], env);
	}
}

void	second_son(int *fd, char **argv, char **env)
{
	int		fd2;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd2 < 0 || access(argv[4], W_OK | R_OK) < 0)
			print_error("Failed to open or access outfile.\n", 1);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(fd2, STDOUT_FILENO);
		close(fd2);
		execute_command(argv[3], env);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	status1;
	int	status2;

	if (argc == 5)
	{
		if (pipe(fd) < 0)
			print_error("Pipe creation failed.\n", 1);
		first_son(fd, argv, env);
		second_son(fd, argv, env);
		if (close(fd[0]) == -1 || close(fd[1]) == -1)
			print_error("Error while closing pipe.\n", 1);
		waitpid(-1, &status1, 0);
		waitpid(-1, &status2, 0);
		if (WEXITSTATUS(status2) != 0)
			return (WEXITSTATUS(status2));
		else
			return (0);
	}
	else
		print_error("Invalid arguments.\n", 1);
}
