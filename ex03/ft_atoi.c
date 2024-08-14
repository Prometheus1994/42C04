/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytlidi <ytlidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:49:00 by ytlidi            #+#    #+#             */
/*   Updated: 2024/08/14 21:37:35 by ytlidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	g_i;
int	g_sign;
int	g_digits_number;
int	g_number;
int	g_k;

int	power_of_ten(int exponent)
{
	int	j;
	int	x;

	j = 1;
	x = 0;
	while (x < exponent)
	{
		j = j * 10;
		x++;
	}
	return (j);
}

void	skipping(int *i, char *str, int *sign)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(char *str)
{
	g_i = 0;
	g_k = 0;
	g_sign = 1;
	g_digits_number = 0;
	g_number = 0;
	skipping(&g_i, str, &g_sign);
	while (str[g_i] >= '0' && str[g_i] <= '9')
	{
		g_digits_number++;
		g_i++;
	}
	while (g_digits_number > 0)
	{
		g_number = g_number + (str[g_i - 1] - '0') * power_of_ten(g_k);
		g_digits_number--;
		g_i--;
		g_k++;
	}
	return (g_sign * g_number);
}
