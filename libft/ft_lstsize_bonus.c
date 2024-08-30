/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:16:17 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/08/26 12:54:18 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*l;

	i = 1;
	l = lst;
	if (lst == NULL)
		return (0);
	while (l->next != NULL)
	{
		i++;
		l = l->next;
	}
	return (i);
}
/* int main() {
	t_list *lst = NULL;
	t_list *new1 = ft_lstnew("1");
	t_list *new2 = ft_lstnew("2");
	t_list *new3 = ft_lstnew("3");
	ft_lstadd_front(&lst, new1);
	ft_lstadd_front(&lst, new2);
	ft_lstadd_front(&lst, new3);
	printf("%d\n", ft_lstsize(lst));
	return (0);
} */