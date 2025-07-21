/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 23:17:49 by jugarcia          #+#    #+#             */
/*   Updated: 2024/09/27 23:31:41 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	k = 0;
	if (size < j || size == 0)
		return (i + size);
	while (src[k] && j + k < size - 1)
	{
		dst[j + k] = src[k];
		k++;
	}
	dst[j + k] = '\0';
	return (j + i);
}
