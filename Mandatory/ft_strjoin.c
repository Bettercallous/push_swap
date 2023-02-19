/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:04:03 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/19 02:07:40 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1len;
	int		s2len;
	char	*str;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (strdup(s2));
	else if (s1 && !s2)
		return (strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(s1len + s2len + 1);
	if (!str)
		return (NULL);
	while (i < s1len)
		str[i++] = *s1++;
	i = 0;
	while (i < s2len)
		str[i++ + s1len] = *s2++;
	str[s1len + s2len] = '\0';
	return (str);
}
