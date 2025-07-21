/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:02:46 by jugarcia          #+#    #+#             */
/*   Updated: 2024/10/02 22:45:55 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free (lst);
}
// #include <stdio.h>

// int main() {
//         t_list *list;
//     list = NULL;
//     char *element1 = strdup("Element 1");
//     char *element2 = strdup("Element 2");
//     char *element3 = strdup("Element 3");
//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     t_list *node3 = malloc(sizeof(t_list));
//     node1->content = element1;
//     node2->content = element2;
//     node3->content = element3;
//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;
//     list = node1;
//     ft_lstclear(&list, free);
//      printf("Lista nueva:\n");
//      while (list)
//      {
//          printf("%s\n", (char *)(list->content));
//          list = list->next;
//      }
//      return 0;
//  }
