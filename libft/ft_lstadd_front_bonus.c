/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:43:28 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/05/07 13:22:17 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	(*lst) = new;
}
/* int main() {
	t_list *lst = NULL;
	t_list *aux = lst;
	t_list *new1 = ft_lstnew("1");
	ft_lstadd_front(&aux, new1);
	printf("%s", (aux)->content);
	printf("\n");
	
	t_list *new2 = ft_lstnew("2");
	ft_lstadd_front(&aux, new2);
	while (aux != NULL)
	{
		printf("%s ->", (aux)->content);
		(aux) = (aux)->next;
	}

	return (0);
} */