/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:39:12 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/06 22:41:17 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	pipex(char *cmd, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		print_error("Pipe creation failed.\n", 1);
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute_command(cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

static int	open_files(int argc, char **argv, int *fd1, int *fd2)
{
	int	i;

	i = 2;
	if (ft_strncmp(argv[1], "here_doc\0", 9) == 0)
	{
		i++;
		*fd2 = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
		if (*fd2 < 0 || access(argv[argc - 1], W_OK | R_OK) < 0)
			print_error("No such file or directory.\n", -1);
		here_doc(argv[2]);
	}
	else
	{
		*fd1 = open(argv[1], O_RDONLY, 0644);
		*fd2 = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (*fd1 < 0 || access(argv[1], R_OK) < 0)
		{
			ft_putstr_fd("No such file or directory.\n", STDERR_FILENO);
			dup2(open("/dev/null", O_RDONLY), STDIN_FILENO);
		}
			//return (ft_putstr_fd("No such file or directory.\n",
			//		STDERR_FILENO), -1);
		if (*fd2 < 0 || access(argv[argc - 1], W_OK | R_OK) < 0)
			print_error("No such file or directory.\n", 1);
		dup2(*fd1, STDIN_FILENO);
		close(*fd1);
	}
	return (i);
}

int	main(int argc, char **argv, char **env)
{
	int		fd1;
	int		fd2;
	int		i;
	int		status;
	pid_t	pid;
	int		last_exitcode;

	last_exitcode = 0;
	if (argc < 5)
		print_error("Invalid arguments.\n", 1);
	else
	{
		i = open_files(argc, argv, &fd1, &fd2);
		if (i < 0)
			i = 2;
		else
		{
			while (i < argc - 2)
				pipex(argv[i++], env);
			dup2(fd2, STDOUT_FILENO);
			close(fd2);
		}
		pid = fork();
		if (pid == 0)
		{
			execute_command(argv[argc - 2], env);
			exit(EXIT_SUCCESS);
		}
		while (1)
		{
			pid = wait(&status);
			if (pid <= 0)
				break ;
			if (WIFEXITED(status))
				last_exitcode = WEXITSTATUS(status);
		}
	}
	return (last_exitcode);
}
