/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytlidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:24:16 by ytlidi            #+#    #+#             */
/*   Updated: 2024/08/10 09:55:44 by ytlidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_i;
int		g_j;
int		g_a;
int		g_flag;
int		g_d;

int	power_of_ten(int exponent)
{
	g_i = 1;
	g_j = 0;
	while (g_j < exponent)
	{
		g_i = g_i * 10;
		g_j++;
	}
	return (g_i);
}

void	inside(int nb)
{
	g_a = 9;
	g_flag = 0;
	while (g_a >= 0)
	{
		if (nb / power_of_ten(g_a) == 0 && g_flag == 0)
		{
			g_a--;
			continue ;
		}
		else
		{
			g_flag = 1;
			g_d = (nb / power_of_ten(g_a)) + '0';
			nb = nb % power_of_ten(g_a);
			write (1, &g_d, 1);
			g_a--;
		}
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb == 0)
	{
		write (1, "0", 1);
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		ft_putnbr(-nb);
	}
	else
	{
		inside(nb);
	}
}
