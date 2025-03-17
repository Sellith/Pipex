/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:28:18 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/17 13:51:49 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"

# define READ 1
# define WRITE 0

typedef struct s_data
{
	char	**files;
	int		filefd[2];
	char	**cmd;
	char	**envp;
	char	*hd_word;
	int		hd;
	int		argc;
}			t_data;

typedef struct s_pids
{
	int		pid;
	void	*next;
}			t_pids;

int		parsing(char **argv, char **envp, t_data *data);
int		separate_args(char **argv, char **envp, t_data *data);
int		check_errors(char **data);
int		mallocstruct(t_data *data, char **argv);
int		verifyfile(t_data *data);
void	freestruct(t_data *data);

#endif
