/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:54:21 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/17 00:54:21 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack	*fill_stack(int ac, char **av)
{
	int			i;
	long int	nb;
	t_stack		*stack_a;

	i = 1;
	nb = 0;
	stack_a = NULL;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			exit_error("Error\n");
		stack_add_last(&stack_a, ft_newstack(nb));
		i++;
	}
	return (stack_a);
}
