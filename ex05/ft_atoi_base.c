/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytlidi <ytlidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:09:35 by ytlidi            #+#    #+#             */
/*   Updated: 2024/08/14 12:05:14 by ytlidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	digit_value(char digit, char *base)
{
	int	i = 0;
	
	while (digit != base[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i = 0;
	int	sign = 1;
	int	digits_number = 0;
	int	number = 0;
	int	k = 0;
	
	if (size(base) < 2 || duplicated(base) == 0
		|| has_forbidden_characters(base) == 0)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] > ' ' && str[i] < 127)
	{
		digits_number++;
		i++;
	}
	while (digits_number > 0)
	{
		number = number + digit_value(str[i - 1], base)
			* power_of_base(base, k);
		digits_number--;
		i--;
		k++;
	}
	return (sign * number);
}
