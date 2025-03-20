/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:18:59 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/20 20:39:41 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc_gnl(int *p_fd, t_data *data)
{
	char	*buffer;

	close(p_fd[0]);
	while (1)
	{
		buffer = get_next_line(0);
		if (ft_strncmp(data->hd_eof, buffer, ft_strlen(data->hd_eof)))
		{
			free(buffer);
			return ;
		}
		ft_putstr_fd(buffer, p_fd[1]);
		free(buffer);
	}
}

int	heredoc_exec(t_data *data)
{
	int	p_fd[2];
	int	pid;

	if (pipe(p_fd) == -1)
		return (perror("Error: Pipe:"), 0);
	pid = fork();
	if (pid == 0)
		heredoc_gnl(p_fd, data);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		if (wait(NULL) == 0)
			return (0);
	}
	return (1);
}
