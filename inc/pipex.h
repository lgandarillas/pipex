/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:37:27 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/06 22:18:19 by lgandari         ###   ########.fr       */
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
int		execute_command(char *cmd, char **env);
void	here_doc(char *delimiter);

#endif
