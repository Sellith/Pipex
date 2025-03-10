/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:41:08 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/10 18:10:28 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	access_cmd(t_data *data)
{
	int		res;
	int		i;
	int		j;
	char	*buffer;
	char	*buff2;

	j = 0;
	while (data->cmd[j] != NULL)
	{
		i = 0;
		res = 0;
		while (data->envp[i] != NULL)
		{
			buff2 = ft_strjoin(data->envp[i++], "/");
			buffer = ft_strjoin(buff2, data->cmd[j]);
			if (access(buffer, F_OK) == 0 && access(buffer, X_OK) == 0)
				res = 1;
			free(buff2);
			free(buffer);
		}
		if (res == 0)
			return (perror("erreur : cmd"), 0);
		j++;
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
			return (printf("ck error"), 1);
		i++;
	}
	return (0);
}

int	separate_args(char **argv, char **envp, t_data *data)
{
	int	i;

	data->files = malloc(sizeof(char *) * 3);
	data->files[0] = ft_strdup(argv[1]);
	data->files[1] = ft_strdup(argv[data->argc]);
	data->files[2] = NULL;
	data->cmd = malloc(sizeof(char *) * (data->argc - 1));
	i = 1;
	if (data->hd == 1)
		data->hd_word = ft_strdup(argv[i++]);
	while (i++ < data->argc - 1)
		data->cmd[i - 2] = ft_strdup(argv[i]);
	data->cmd[i - 2] = NULL;
	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	data->envp = ft_split(envp[i] + 5, ':');
	if (((!access(data->files[1], F_OK)
				|| !access(data->files[1], W_OK)))
		|| (!access(data->files[0], F_OK) || !access(data->files[0], R_OK)
			|| !access(data->files[1], F_OK) || !access(data->files[1], W_OK)))
		return (printf("sep : 2\n%s\n", data->files[1]), 0);
	return (1);
}

int	parsing(char **argv, char **envp, t_data *data)
{

	if (data->argc < 4)
		return (perror("error : incorect number of args"), 0);
	if (ft_strlen(argv[1]) == 8 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		data->hd = 1;
	if (separate_args(argv, envp, data) == 0 || check_errors(data->files) == 1
		|| check_errors(data->cmd) == 1 || access_cmd(data) == 0)
		return (freestruct(data), 0);
	return (1);
}
