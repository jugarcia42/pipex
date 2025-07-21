/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:56:25 by jugarcia          #+#    #+#             */
/*   Updated: 2024/09/27 19:40:35 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = s;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}
