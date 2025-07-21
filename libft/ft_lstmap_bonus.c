/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:18:34 by jugarcia          #+#    #+#             */
/*   Updated: 2024/10/03 19:29:02 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;
	void	*res_f;

	if (!f || !del || !lst)
		return (NULL);
	result = NULL;
	while (lst)
	{
		res_f = f(lst->content);
		temp = ft_lstnew(res_f);
		if (!temp)
		{
			ft_lstclear(&result, del);
			del(res_f);
			return (NULL);
		}
		ft_lstadd_back(&result, temp);
		lst = lst->next;
	}
	return (result);
}
