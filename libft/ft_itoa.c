/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:38:31 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/09/19 19:41:23 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(int n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		result++;
		n = -n;
	}
	while (n)
	{
		result++;
		n /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int			num_of_chars;
	char		*result;

	num_of_chars = get_num_len(n);
	result = (char *)malloc(sizeof(char) * (num_of_chars + 1));
	if (!result)
		return (NULL);
	result[num_of_chars] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n)
	{
		if (n > 0)
			result[--num_of_chars] = (n % 10) + '0';
		else
			result[--num_of_chars] = ((n % 10) * -1) + '0';
		n /= 10;
	}
	return (result);
}
/*
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(-1));
	return (0);
}
*/
