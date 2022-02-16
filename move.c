/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:32:46 by acash             #+#    #+#             */
/*   Updated: 2021/12/13 21:32:47 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_right(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j] && g->map[i][j] != 'P')
			j++;
		if (g->map[i][j] == 'P')
			break ;
		i++;
	}
	ft_change_anim("./assets/player3.xpm", g);
	if (ft_events(g, g->map[i][j + 1]) && g->end_flag == 0)
	{
		g->map[i][j] = '0';
		g->map[i][j + 1] = 'P';
		ft_putnbr(++g->step);
		ft_putchar('\n');
	}
}

void	ft_move_left(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j] && g->map[i][j] != 'P')
			j++;
		if (g->map[i][j] == 'P')
			break ;
		i++;
	}
	ft_change_anim("./assets/player4.xpm", g);
	if (ft_events(g, g->map[i][j - 1]) && g->end_flag == 0)
	{
		g->map[i][j] = '0';
		g->map[i][j - 1] = 'P';
		ft_putnbr(++g->step);
		ft_putchar('\n');
	}
}

void	ft_move_up(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j] && g->map[i][j] != 'P')
			j++;
		if (g->map[i][j] == 'P')
			break ;
		i++;
	}
	ft_change_anim("./assets/player1.xpm", g);
	if (ft_events(g, g->map[i - 1][j]) && g->end_flag == 0)
	{
		g->map[i][j] = '0';
		g->map[i - 1][j] = 'P';
		ft_putnbr(++g->step);
		ft_putchar('\n');
	}
}

void	ft_move_down(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j] && g->map[i][j] != 'P')
			j++;
		if (g->map[i][j] == 'P')
			break ;
		i++;
	}
	ft_change_anim("./assets/player5.xpm", g);
	if (ft_events(g, g->map[i + 1][j]) && g->end_flag == 0)
	{
		g->map[i][j] = '0';
		g->map[i + 1][j] = 'P';
		ft_putnbr(++g->step);
		ft_putchar('\n');
	}
}
