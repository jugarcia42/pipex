/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:12:53 by jugarcia          #+#    #+#             */
/*   Updated: 2024/09/26 19:49:34 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destinatario;
	char	*recurso;

	i = 0;
	destinatario = (char *)dest;
	recurso = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (destinatario > recurso)
	{
		while (n-- > 0)
			destinatario[n] = recurso[n];
	}
	else
	{
		while (i < n)
		{
			destinatario[i] = recurso[i];
			i++;
		}
	}
	return (dest);
}
