/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:50:31 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/04/24 19:06:44 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	if (s1)
		ft_memcpy(s, s1, ft_strlen(s1));
	if (s2)
		ft_memcpy(s + ft_strlen(s1), s2, ft_strlen(s2));
	s[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (s);
}

/* int main() {
    char *s1 = "hello";
    char *s2 = "goodbye";
    char *str = ft_strjoin(s1, s2);
    printf("%s\n", str);
    return (0);
} */