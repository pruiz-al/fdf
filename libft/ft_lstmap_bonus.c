/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:26:59 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/05/06 18:14:40 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*n;

	l = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		n = ft_lstnew(f(lst->content));
		if (!n)
		{
			ft_lstclear(&l, del);
			return (NULL);
		}
		ft_lstadd_back(&l, n);
		lst = lst->next;
	}
	return (l);
}
