/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:53:09 by omartine          #+#    #+#             */
/*   Updated: 2022/02/15 19:28:26 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	wordcount(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			i++;
		else
		{
			words++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
	}
	return (words);
}

int	position(char const *s, int pos, char c, int flg)
{
	if (flg == 1)
	{
		while (s[pos] == c && s[pos] != 0)
			pos++;
		return (pos);
	}
	while (s[pos] != c && s[pos] != 0)
		pos++;
	return (pos);
}

void	*free_split(char **aux, int words)
{
	int	i;

	i = 0;
	while (i <= words)
	{
		free(aux[i]);
		i++;
	}
	free(aux);
	return (0);
}

char	*word(char const *s, int in, int fin)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char *) malloc(sizeof(char) * (fin - in + 1));
	if (!aux)
		return (0);
	aux[fin - in] = 0;
	while (in < fin)
	{
		aux[i] = s[in];
		in++;
		i++;
	}
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	int		in;
	int		i;
	int		count;
	char	**aux;

	in = 0;
	i = 0;
	if (!s)
		return (0);
	count = wordcount(s, c);
	aux = (char **) malloc(sizeof(char *) * (count + 1));
	if (!aux)
		return (0);
	aux[count] = 0;
	while (i < count)
	{
		in = position(s, in, c, 1);
		aux[i] = word(s, in, position(s, in, c, 0));
		if (!aux[i])
			return (free_split(aux, count));
		in = position(s, in, c, 0);
		i++;
	}
	return (aux);
}
