/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:57:13 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/15 14:22:45 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	**get_multiplier(t_stock_nbr *stock)
{
	char	**multiplier;
	int		i;
	static int	times;
	int		counter;
	int		buf_idx;

	counter = 0;
	i = 0;
	times
	while (stock[i].end != 1)
	{
		if (stock[i].nbr >= 1000)
		{
			ft_putstr(stock[i].str);
			ft_putchar('\n');
			counter++;
		}
		i++;
	}
	ft_putnbr(counter);
	if (counter == 0)
		return (NULL);
	multiplier = (char **)malloc(sizeof(char *) * (counter + 2));
	if (!multiplier)
		return (NULL);
	buf_idx = 0;
	multiplier[buf_idx++] = NULL;
	while (i >= 0 && stock[--i].nbr >= 1000)
	{
		multiplier[buf_idx++] = stock[i].str;
		// ft_putstr(multiplier[buf_idx - 1]);
		// ft_putchar('\n');
	}
	multiplier[buf_idx] = NULL;
	return (multiplier);
}

char	**get_first_twenty(void)
{
	char	**first_twenty;

	first_twenty = (char **)malloc(sizeof(char *) * 20);
	if (first_twenty == NULL)
		return (NULL);
	first_twenty[0] = ft_strdup("");
	first_twenty[1] = ft_strdup("one");
	first_twenty[2] = ft_strdup("two");
	first_twenty[3] = ft_strdup("three");
	first_twenty[4] = ft_strdup("four");
	first_twenty[5] = ft_strdup("five");
	first_twenty[6] = ft_strdup("six");
	first_twenty[7] = ft_strdup("seven");
	first_twenty[8] = ft_strdup("eight");
	first_twenty[9] = ft_strdup("nine");
	first_twenty[10] = ft_strdup("ten");
	first_twenty[11] = ft_strdup("eleven");
	first_twenty[12] = ft_strdup("twelve");
	first_twenty[13] = ft_strdup("thirteen");
	first_twenty[14] = ft_strdup("fourteen");
	first_twenty[15] = ft_strdup("fifteen");
	first_twenty[16] = ft_strdup("sixteen");
	first_twenty[17] = ft_strdup("seventeen");
	first_twenty[18] = ft_strdup("eighteen");
	first_twenty[19] = ft_strdup("nineteen");
	return (first_twenty);
}

char	**get_tens(void)
{
	char	**tens;

	tens = (char **)malloc(sizeof(char *) * 9);
	if (tens == NULL)
		return (NULL);
	tens[0] = ft_strdup("");
	tens[1] = ft_strdup("twenty");
	tens[2] = ft_strdup("thirty");
	tens[3] = ft_strdup("forty");
	tens[4] = ft_strdup("fifty");
	tens[5] = ft_strdup("sixty");
	tens[6] = ft_strdup("seventy");
	tens[7] = ft_strdup("eighty");
	tens[8] = ft_strdup("ninety");
	return (tens);
}
