/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_garbage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:20:54 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/02/13 11:22:02 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_garbage(t_garbage *garbage)
{
	if (garbage->split_pipe)
	{
		ft_free_tab(garbage->split_pipe);
		garbage->split_pipe = NULL;
	}
	if (garbage->split_lst)
	{
		free_split_elem(garbage->split_lst);
		garbage->split_lst = NULL;
	}
	if (garbage->maillons)
	{
		free_maillons(&garbage->maillons);
		garbage->maillons = NULL;
	}
	if (garbage->pipes)
	{
		free_all_pipes(garbage->pipes->len, garbage->pipes);
		garbage->pipes = NULL;
	}
	if (garbage->line)
	{
		free(garbage->line);
		garbage->line = NULL;
	}
}

void	free_garbage_and_env(t_garbage *garbage)
{
	if (garbage->split_pipe)
		ft_free_tab(garbage->split_pipe);
	if (garbage->split_lst)
		free_split_elem(garbage->split_lst);
	if (garbage->maillons)
		free_maillons(&garbage->maillons);
	if (garbage->pipes)
	//	free_all_pipes(garbage->pipes->len, *garbage->pipes);
	if (garbage->line)
		free(garbage->line);
	if (garbage->new_env);
		ft_free_tab(garbage->new_env);
}

/*void    free_garbage_exit(t_garbage *garbage)
{
	if (garbage->split_pipe)
		ft_free_tab(garbage->split_pipe);
	if (garbage->split_lst)
		free_split_elem(garbage->split_lst);
	if (garbage->maillons)
		free_maillons(&garbage->maillons);
	if (garbage->pipes)
		free_all_pipes(garbage->pipes->len, *garbage->pipes);
	exit(1);
}*/