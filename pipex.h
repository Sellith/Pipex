/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:28:18 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/20 20:39:51 by lvan-bre         ###   ########.fr       */
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
# include "../Get_Next_Line/get_next_line.h"

# define READ 1
# define WRITE 0

typedef struct s_pids
{
	int				pids;
	struct s_pids	*next;
}					t_pids;

typedef struct s_data
{
	char	**cmd;
	int		cmdcnt;
	char	**envp;
	char	**files;
	int		filefd[2];
	char	*hd_eof;
	int		hd;
	int		argc;
	t_pids	*pid;
}			t_data;

///////////////////////////////////////
/*              parsing              */
///////////////////////////////////////

int		separate_args(char **argv, char **envp, t_data *data);
int		check_errors(char **data);
int		mallocstruct(t_data *data, char **argv);
int		parsing(char **argv, char **envp, t_data *data);

///////////////////////////////////////
/*             execution             */
///////////////////////////////////////

char	*findpath(char **envp, char *cmd);
int		files_opening(t_data *data);
int		do_pipe(char *path, t_pids *pid, char **env, char *cmd);
int		pipex_exec(t_data *data, char **env);
void	heredoc_gnl(int *p_fd, t_data *data);
int		heredoc_exec(t_data *data);

///////////////////////////////////////
/*          linked list utils        */
///////////////////////////////////////

t_pids	*new(int content);
void	add_back(t_pids **lst, t_pids *new);

///////////////////////////////////////
/*          memory management        */
///////////////////////////////////////

void	freestruct(t_data *data);
void	freelst(t_list *data);

#endif
