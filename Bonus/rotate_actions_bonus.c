/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:43:17 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/13 21:43:17 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = ft_stacklast(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
