/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:30:57 by jugarcia          #+#    #+#             */
/*   Updated: 2024/09/27 16:59:39 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uno;
	unsigned char	*dos;

	if (n == 0)
		return (0);
	uno = (unsigned char *)s1;
	dos = (unsigned char *)s2;
	while ((*uno == *dos) && (n - 1 > 0))
	{
		uno++;
		dos++;
		n--;
	}
	return ((int)(*uno - *dos));
}
/*


// Prototipo de la función ft_memcmp
int ft_memcmp(const void *s1, const void *s2, size_t n);

int main() {
    const char str1[] = "Hola, mundo!";
    const char str2[] = "Hola, Mundo!";
    size_t n = 5;

    int result = ft_memcmp(str1, str2, n);

    if (result == 0) {
        printf("Los primeros %zu bytes de las cadenas son iguales.\n", n);
    } else {
        printf("Los primeros %zu bytes de las cadenas son diferentes.\n", n);
    }

    return 0;
}
*/
