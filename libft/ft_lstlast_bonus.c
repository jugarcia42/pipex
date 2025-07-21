/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:47:50 by jugarcia          #+#    #+#             */
/*   Updated: 2024/10/02 22:15:32 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}
// int main(void)
// {
//     t_list *node1 = ft_lstnew("Nodo 1");
//     t_list *node2 = ft_lstnew("Nodo 2");
//     t_list *node3 = ft_lstnew("Nodo 3");

//     node1->next = node2;
//     node2->next = node3;

//     t_list *last = ft_lstlast(node1);

//     if (last)
//         printf("El último nodo contiene: %s\n", (char *)last->content);
//     else
//         printf("La lista está vacía o es NULL.\n");
// }