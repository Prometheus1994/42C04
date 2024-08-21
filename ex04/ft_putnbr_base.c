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

	i = 0;
	while (i < size(base))
	{
		j = i + 1;
		while (j < size(base))
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
	int	k = 0;

	while (base[k] != '\0')
	{
		if (base[k] == '+' || base[k] == '-' || base[k] == ' '
			|| (base[k] >= 9 && base[k] <= 13))
			return (0);
		k++;
	}
	return (1);
}

int	power_of_base(char *base, int exponent)
{
	int	i = 1;
	int	j = 0;
	
	while (j < exponent)
	{
		i = i * size(base);
		j++;
	}
	return (i);
}

void	inside(int nbr, char *base)
{
	int a = 31;
	int flag = 0;
	char d;

	while (a >= 0)
	{
		if (nbr / power_of_base(base, a) == 0 && flag == 0)
		{
			a--;
			continue ;
		}
		else
		{
			flag = 1;
			d = base[nbr / power_of_base(base, a)];
			nbr = nbr % power_of_base(base, a);
			write (1, &d, 1);
			a--;
		}
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (nbr == 0)
	{
		write (1, &base[0], 1);
	}
	else if (nbr < 0)
	{
		write (1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	else
	{
		inside(nbr, base);
	}
}
