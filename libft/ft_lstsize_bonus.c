/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:39:36 by jugarcia          #+#    #+#             */
/*   Updated: 2024/10/02 22:48:10 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cont;

	cont = 0;
	while (lst)
	{
		lst = lst -> next;
		cont++;
	}
	return (cont);
}

// int main()
// {
// 	t_list *new;
// 	t_list *new_head;
// 	new = ft_lstnew(0);
// 	new_head = ft_lstnew(1);
// 	ft_lstadd_front(&new, new_head);
// 	printf("%d",ft_lstsize(new_head));
// }
