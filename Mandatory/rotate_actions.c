/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:33:43 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/15 11:33:43 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr("ra\n", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n", 1);
}
