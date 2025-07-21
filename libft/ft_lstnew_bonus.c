/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:28:09 by jugarcia          #+#    #+#             */
/*   Updated: 2024/10/02 18:02:54 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list -> content = content;
	list -> next = NULL;
	return (list);
}
/*
int	main()
{
	int	a = 1234;
	t_list	*nodo;
	nodo = ft_lstnew(a); 
	printf("%d\n", nodo->content);
}*/
