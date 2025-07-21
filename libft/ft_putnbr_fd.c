/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:42:44 by jugarcia          #+#    #+#             */
/*   Updated: 2024/10/01 21:46:50 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(int nbr)
{
	int	cnt;

	cnt = 0;
	while (nbr)
	{
		nbr /= 10;
		cnt++;
	}
	return (cnt);
}

static void	calc(unsigned int nbr, int len, int fd)
{
	int	n;

	while (len--)
		nbr /= 10;
	n = (nbr % 10) + '0';
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	num;
	int				size;

	if (nb < 0)
	{
		num = nb * -1;
		write(fd, "-", 1);
	}
	else
		num = nb;
	if (num == 0)
		write(fd, "0", 1);
	size = counter(num);
	while (size--)
		calc(num, size, fd);
}
