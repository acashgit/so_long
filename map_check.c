/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:31:49 by acash             #+#    #+#             */
/*   Updated: 2021/12/10 16:31:53 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	symbol_check(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1' || g->map[i][j] == '0'
				|| g->map[i][j] == 'C' || g->map[i][j] == 'E'
				|| g->map[i][j] == 'P' || g->map[i][j] == 'W')
			{
				if (g->map[i][j] == 'W')
					g->enemy += 1;
				if (g->map[i][j] == 'C')
					g->maxcoin += 1;
				j++;
				continue ;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	objincc(t_game *g)
{
	if (g->wall == 1 && g->collect == 1
		&& g->exit == 1
		&& g->player == 1)
		return (0);
	return (1);
}

int	objinc(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1')
				g->wall = 1;
			else if (g->map[i][j] == '0')
				g->empty = 1;
			else if (g->map[i][j] == 'C')
				g->collect = 1;
			else if (g->map[i][j] == 'E')
				g->exit = 1;
			else if (g->map[i][j] == 'P')
				g->player += 1;
			j++;
		}
		i++;
	}
	return (objincc(g));
}

int	checkweid(t_game *g)
{
	int	i;
	int	save;

	save = ft_strlen(g->map[0]);
	i = 1;
	while (g->map[i])
	{
		if (ft_strlen(g->map[i]) != save)
			return (1);
		i++;
	}
	g->floor = i;
	return (0);
}

void	map_step(t_game *g)
{
	if (symbol_check(g) || objinc(g) || checkweid(g)
		|| checkends(g))
		ft_error(2);
}
