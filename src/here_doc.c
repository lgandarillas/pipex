/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:43:57 by lgandari          #+#    #+#             */
/*   Updated: 2024/04/14 16:45:12 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	get_line(int *fd, char *delimiter)
{
	char	*line;

	close(fd[0]);
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0 \
			&& ft_strlen(line) == ft_strlen(delimiter) + 1)
			exit(EXIT_SUCCESS);
		write(1, "pipe heredoc> ", 14);
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

void	here_doc(char *delimiter)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		write(1, "pipe heredoc> ", 14);
		get_line(fd, delimiter);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		wait(NULL);
	}
}
