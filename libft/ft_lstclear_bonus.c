/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:11:28 by jugarcia          #+#    #+#             */
/*   Updated: 2024/10/03 19:37:57 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;

	while (*lst)
	{
		list = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = list;
	}
}
/*
int	main(void) {
	t_list *list;
		list = NULL;
	t_list *element1 = ft_lstnew("Element 1");
	t_list *element2 = ft_lstnew("Element 2");
	t_list *element3 = ft_lstnew("Element 3");
	ft_lstadd_front(&list, element3);
	ft_lstadd_front(&list, element2);
	ft_lstadd_front(&list, element1);
	while (list) {
		printf("%s\n", (char *)(list->content));
		list = list->next;
	}
		ft_lstclear(&list, free);
		while (list == NULL)
				return(printf("Vacio\n"));
	return (0);
}*/
