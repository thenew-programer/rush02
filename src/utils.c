/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:54:50 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/15 09:15:43 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\v')
		return (TRUE);
	return (FALSE);
}

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	get_word_len(char *str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i] && str[i] !=  ':')
		i++;
	while (str[i])
	{
		if (str[i] == '\0' && len == 0)
			return (-1);
		while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
			i++;
		if (len > 0)
			len++;
		while ((str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13)) && str[i])
		{
			len++;
			i++;
		}
	}
	return (len);
}

char	*ft_strlcpy(char *dest, char *src, int size)
{
	int	i;
	int	buf_idx;

	i = 0;
	buf_idx = 0;
	while (src[i] && i < size - 1)
	{
		while ((src[i] == ' ' || (src[i] >= 9 && src[i] <= 13)) && src[i])
			i++;
		if (buf_idx > 0)
			dest[buf_idx++] = ' ';
		while (src[i] > ' ' && src[i] <= '~' && src[i])
			dest[buf_idx++] = src[i++];

	}
	dest[buf_idx] = '\0';
	return (dest);
}

char	*ft_clean_strdup(char *str, int size)
{
	int		i;
	int		buf_idx;
	char	*trimed_str;
	int		len;

	len = get_word_len(str);
	trimed_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!trimed_str)
	{
		g_error = MEMORY_ERROR;
		return (NULL);
	}

	buf_idx = 0;
	i = 0;
	while (str[i] && str[i] != ':')
		i++;
	trimed_str = ft_strlcpy(trimed_str, (str + i + 1), size);
	return (trimed_str);
}

void	free_stock(t_stock_nbr	*stock)
{
	int	i;

	i = 0;
	while (stock[i].end != 1)
	{
		free(stock[i].str);
		i++;
	}
	free(stock);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(__int128 nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr / 10)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

char	*search_stock(t_stock_nbr *stock, t_ui128 nbr)
{
	int	i;

	i = 0;
	while (stock[i].end != 1)
	{
		if (nbr == stock[i].nbr)
			return (stock[i].str);
	}
	return (NULL);
}
