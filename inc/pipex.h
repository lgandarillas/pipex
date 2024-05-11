/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:37:27 by lgandari          #+#    #+#             */
/*   Updated: 2024/04/14 16:42:42 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "../libft_v2/inc/libft.h"
# include "../libft_v2/inc/get_next_line.h"
# include "../libft_v2/inc/ft_printf.h"

int		print_error(char *msg, int exit_code);
void	free_split(char **split);
int		get_path_index(char **env);
char	*get_path(char *cmd, char **env);
int		execute_command(char *cmd, char **env);

void	here_doc(char *delimiter);
void	get_line(int *fd, char *delimiter);

#endif
