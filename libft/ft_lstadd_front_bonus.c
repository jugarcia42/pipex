/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:45:42 by jugarcia          #+#    #+#             */
/*   Updated: 2024/10/02 22:47:07 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
// int main(void)
// {
// 	t_list *a;
// 	t_list *b;

// 	a = ft_lstnew(0);
// 	b = ft_lstnew(1);
// 	ft_lstadd_front(&a, b);
// 	printf("%d", b->content);
// 	b = b->next;
// 	printf("%d", b->content);
// }
