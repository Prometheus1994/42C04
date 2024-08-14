/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytlidi <ytlidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:03:42 by ytlidi            #+#    #+#             */
/*   Updated: 2024/08/12 10:15:59 by ytlidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int	size(char *base)
{
	int	size;

	size = 0;
	while (base[size] != '\0')
		size++;
	return (size);
}

int	duplicated(char *base)
{
	int	i;
	int	j;
	int	s;

	s = size(base);
	i = 0;
	while (i < s)
	{
		j = i + 1;
		while (j < s)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_forbidden_characters(char *base)
{
	int	k;

	k = 0;
	while (base[k] != '\0')
	{
		if (base[k] == '+' || base[k] == '-' || base[k] == ' '
			|| (base[k] >= 9 && base[k] <= 13))
			return (0);
		k++;
	}
	return (1);
}

void	inside(unsigned int n, char *base, int sign)
{
	unsigned int	base_size;

	base_size = size(base);
	if ((unsigned int)(sign * n) > base_size - 1)
		ft_putnbr_base((unsigned int)(sign * (n / base_size)), base);
	write(1, &base[(unsigned int)(sign * (n % base_size))], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (size(base) < 2 || duplicated(base) == 0
		|| has_forbidden_characters(base) == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		inside(nbr, base, -1);
	}
	else
		inside(nbr, base, 1);
}
