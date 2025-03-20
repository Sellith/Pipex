/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:41:08 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/20 20:38:03 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	mallocstruct(t_data *data, char **argv)
{
	data->files = malloc(sizeof(char *) * 3);
	if (data->files == NULL)
		return (0);
	data->files[0] = ft_strdup(argv[1]);
	if (data->files[0] == NULL)
		return (0);
	data->files[1] = ft_strdup(argv[data->argc]);
	if (data->files[1] == NULL)
		return (0);
	data->files[2] = NULL;
	data->cmd = malloc(sizeof(char *) * (data->argc - 1));
	if (data->cmd == NULL)
		return (0);
	data->envp = NULL;
	if (data->hd == 1)
	{
		data->hd_eof = ft_strdup(argv[2]);
		if (data->hd_eof == NULL)
			return (0);
	}
	return (1);
}

int	check_errors(char **sent)
{
	int	i;
	int	len;

	i = 0;
	len = darraylen(sent);
	while (i < len)
	{
		while (*sent[i] == ' ' || *sent[i] == '	')
			sent[i]++;
		if (*sent[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	separate_args(char **argv, char **envp, t_data *data)
{
	int	i;

	if (mallocstruct(data, argv) == 0)
		return (0);
	data->cmdcnt = 0;
	i = 1;
	while (i++ + data->hd < data->argc - 1)
	{
		data->cmd[i - 2] = ft_strdup(argv[i + data->hd]);
		if (data->cmd == NULL)
			return (0);
		data->cmdcnt++;
	}
	data->cmd[i - 2] = NULL;
	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL && i < darraylen(envp) - 1)
		i++;
	if (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		return (perror("Error: no set path"), 0);
	data->envp = ft_split(envp[i] + 5, ':');
	if (data->envp == NULL)
		return (0);
	return (1);
}

int	parsing(char **argv, char **envp, t_data *data)
{
	data->hd = 0;
	if (ft_strlen(argv[1]) == 8 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		data->hd = 1;
	if (data->argc < 4 + data->hd)
		return (perror("Error: incorrect number of args"), 0);
	if (separate_args(argv, envp, data) == 0 || check_errors(data->files) == 1
		|| check_errors(data->cmd) == 1)
		return (freestruct(data), 0);
	return (1);
}
