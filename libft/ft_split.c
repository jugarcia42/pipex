/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:41:12 by jugarcia          #+#    #+#             */
/*   Updated: 2024/10/03 20:42:57 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	key_word(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

static int	cont(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!key_word(str[i], c) && (key_word(str[i + 1], c)
				|| str[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

static int	write_str(char **r, char *str, char c)
{
	int	i;
	int	j;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (key_word(str[i], c))
			i++;
		else
		{
			j = 0;
			while (!key_word(str[i + j], c) && str[i + j])
				j++;
			r[words] = ft_substr(str, i, j);
			if (r[words] == NULL)
				return (free_str(r));
			i += j;
			words++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**res;

	if (!s)
		return (NULL);
	words = cont((char *)s, c);
	res = ft_calloc(words + 1, sizeof(char *));
	if (!res)
		return (NULL);
	if (!write_str(res, (char *)s, c))
		return (NULL);
	return (res);
}
