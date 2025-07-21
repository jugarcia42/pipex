/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:55:33 by jugarcia          #+#    #+#             */
/*   Updated: 2024/10/02 22:46:24 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*result;

	if (*lst)
	{
		result = ft_lstlast(*lst);
		result -> next = new;
	}
	else
		*lst = new;
}
// int main(void)
// {
//     t_list *head = ft_lstnew("Nodo 1");
//     t_list *node2 = ft_lstnew("Nodo 2");
//     t_list *node3 = ft_lstnew("Nodo 3");

//     ft_lstadd_back(&head, node2);
//     ft_lstadd_back(&head, node3);

//     t_list *last = ft_lstlast(head);

//     if (last)
//         printf("El último nodo contiene: %s\n", (char *)last->content);
//     else
//         printf("La lista está vacía o es NULL.\n");

//     free(head);
//     free(node2);
//     free(node3);

//     return 0;
// }
