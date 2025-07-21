/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:40:19 by jugarcia          #+#    #+#             */
/*   Updated: 2024/09/26 20:20:43 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = s;
	while (i < n)
	{
		a[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
