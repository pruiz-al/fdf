/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:24:46 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/05/07 13:00:42 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = malloc(sizeof(struct s_list));
	if (l == NULL)
		return (NULL);
	l->content = content;
	l->next = NULL;
	return (l);
}
/*
int	main() {
	t_list	*l = ft_lstnew("42");
	printf("%s", l->content);
	return (0);
}*/