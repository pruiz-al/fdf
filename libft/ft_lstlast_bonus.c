/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:30:00 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/05/07 13:21:49 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*l;

	l = lst;
	if (lst == NULL)
		return (NULL);
	while (l->next != NULL)
		l = l->next;
	return (l);
}
/* int main() {
	t_list *lst = NULL;
	t_list *new1 = ft_lstnew("1");
	t_list *new2 = ft_lstnew("2");
	t_list *new3 = ft_lstnew("3");
	ft_lstadd_front(&lst, new1);
	ft_lstadd_front(&lst, new2);
	ft_lstadd_front(&lst, new3);
	t_list *last = ft_lstlast(lst);
	printf("%s\n", last->content);
	return(0);
} */