/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:33:34 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/05/07 13:24:28 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	l = (*lst);
	if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		while (l->next != NULL)
			l = l->next;
		l->next = new;
	}
}
/* int main() {
	t_list *lst = NULL;
	t_list *aux = lst;
	t_list *new1 = ft_lstnew("1");
	ft_lstadd_back(&aux, new1);
	printf("%s", (aux)->content);
	printf("\n");
	
	t_list *new2 = ft_lstnew("2");
	ft_lstadd_back(&aux, new2);
	while (aux != NULL)
	{
		printf("%s ->", (aux)->content);
		(aux) = (aux)->next;
	}

	return (0);
}  */