/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:29:09 by jugarcia          #+#    #+#             */
/*   Updated: 2024/09/27 22:05:20 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*de;
	unsigned char	*sr;
	size_t			i;

	de = (unsigned char *)dest;
	sr = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (len > i)
	{
		de[i] = sr[i];
		i++;
	}
	return (dest);
}
