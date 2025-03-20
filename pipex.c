/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:03:09 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/20 20:41:28 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*findpath(char **envp, char *cmd)
{
	char	*buffer;
	char	*res;
	int		i;

	buffer = ft_strjoin("/", cmd);
	while (envp[i] != NULL)
	{
		res = ft_strjoin(envp[i], buffer);
		if (access(buffer, F_OK) == 0 && access(buffer, X_OK) == 0)
		{
			free(buffer);
			free(res);
			return (envp[i]);
		}
		free(res);
		i++;
	}
	free(buffer);
	return (perror("erreur : cmd"), NULL);
}

void	waitall(t_pids *data)
{
	t_pids	*pid;

	pid = data;
	while (pid != NULL)
	{
		waitpid(pid->pids, NULL, 0);
		pid = pid->next;
	}
}

int	files_opening(t_data *data)
{
	if (data->hd == 0)
	{
		data->filefd[0] = open(data->files[0], O_RDONLY | O_CREAT, 0644);
		if (data->filefd[0] == -1)
			return (perror("Error: Infile access"), 0);
	}
	data->filefd[1] = open(data->files[1], O_WRONLY | O_CREAT, 0644);
	if (data->filefd[1] == -1)
		return (perror("Error: Oufile access"), 0);
	return (1);
}

int	do_pipe(char *path, t_pids *pid, char **env, char *cmd)
{
	int		p_fd[2];
	int		tmpid;

	if (pipe(p_fd) == -1)
		return (0);
	tmpid = fork();
	if (tmpid == -1)
		return (perror("Error: Fork"), 0);
	if (tmpid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], STDOUT_FILENO);
		close(p_fd[1]);
		if (execve(path, cmd, env) == -1)
			return (perror("Error: Cmd"), 0);
	}
	else
	{
		add_back(&pid, new(tmpid));
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		close(p_fd[0]);
	}
	return (1);
}

int	pipex_exec(t_data *data, char **env)
{
	t_pids	*current;
	char	*path;
	int		i;

	current = data->pid;
	if (data->hd == 1)
		if (heredoc_exec(data) == 0)
			return (freestruct(data), 0);
	else
		dup2(data->filefd[0], STDIN_FILENO);
	i = -1;
	while (++i < data->cmdcnt)
	{
		path = findpath(data->envp, data->cmd[i]);
		if (path == NULL || do_pipe(path, &current, env, data->cmd[i]) == 0)
			return (freestruct(data), 0);
		current = current->next;
	}
	dup2(data->filefd[1], STDOUT_FILENO);
	close(data->filefd[1]);
	path = findpath(data->envp, data->cmd[i]);
	if (execve(path, data->cmd, env) == -1)
		return (freestruct(data), 0);
	waitall(data->pid);
	return (1);
}
